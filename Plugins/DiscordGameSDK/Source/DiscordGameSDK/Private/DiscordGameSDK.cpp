// Copyright 2020 NIRV Team LLC. All Rights Reserved.
//
#include "DiscordGameSDK.h"

#include "DiscordGameSDKSettings.h"
#include <Interfaces/IPluginManager.h>
#include <Misc/MessageDialog.h>
#if WITH_EDITOR
#include <Subsystems/AssetEditorSubsystem.h>
#include <EditorModeManager.h>
#endif

#define LOCTEXT_NAMESPACE "FDiscordGameSDKModule"

DEFINE_LOG_CATEGORY_STATIC(LogDiscord, All, All)


static discord::Core* CoreInstance = nullptr;

void FDiscordGameSDKModule::StartupModule()
{
#if defined(DISCORD_DYNAMIC_LIB)
	const FString BaseDirectory = IPluginManager::Get().FindPlugin("DiscordGameSDK")->GetBaseDir();
	const FString SDKDirectory = FPaths::Combine(*BaseDirectory, TEXT("Source"), TEXT("ThirdParty"), TEXT("DiscordGameSDKLibrary"));
	const FString LibraryName = TEXT("discord_game_sdk");
	const FString LibraryDirectory = FPaths::Combine(*SDKDirectory, TEXT("Win64"));

	if (!LoadDependency(LibraryDirectory, LibraryName, DiscordGameSDKLibraryHandle))
	{
		FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT(LOCTEXT_NAMESPACE, "Failed to load DiscordGameSDK plugin."));
		FreeDependency(DiscordGameSDKLibraryHandle);
	}
#endif

	SetupDiscord();

	TickDelegate = FTickerDelegate::CreateRaw(this, &FDiscordGameSDKModule::Tick);
	TickDelegateHandle = FTicker::GetCoreTicker().AddTicker(TickDelegate);
}

void FDiscordGameSDKModule::ShutdownModule()
{
#if defined(DISCORD_DYNAMIC_LIB)
	FreeDependency(DiscordGameSDKLibraryHandle);
#endif

	FTicker::GetCoreTicker().RemoveTicker(TickDelegateHandle);
}

bool FDiscordGameSDKModule::Tick(float InDeltaTime)
{
#if defined(DISCORD_DYNAMIC_LIB)
	if (CoreInstance)
	{
#if WITH_EDITOR
		UpdateFocusedWindowStatus();
#endif

		return CoreInstance->RunCallbacks() == discord::Result::Ok;
	}
#endif

	return true;
}

bool FDiscordGameSDKModule::LoadDependency(const FString& InDirectory, const FString& InName, void*& InHandle)
{
	const FString Library = InName + TEXT(".") + FPlatformProcess::GetModuleExtension();
	const FString Path = InDirectory.IsEmpty() ? *Library : FPaths::Combine(*InDirectory, *Library);

	InHandle = FPlatformProcess::GetDllHandle(*Path);

	if (InHandle == nullptr) return false;

	return true;
}

void FDiscordGameSDKModule::FreeDependency(void*& InHandle)
{
	if (InHandle != nullptr)
	{
		FPlatformProcess::FreeDllHandle(InHandle);
		InHandle = nullptr;
	}
}

void FDiscordGameSDKModule::SetupDiscord()
{
#if defined(DISCORD_DYNAMIC_LIB)
	FString RawClientID;
	FString RawCreateFlag;
	FString DefaultLogo;
	discord::Timestamp Time = FDateTime::UtcNow().ToUnixTimestamp();

#if WITH_EDITOR
	FString ProjectName;
	GConfig->GetString(TEXT("/Script/EngineSettings.GeneralProjectSettings"), TEXT("ProjectName"), ProjectName, GGameIni);
	GConfig->GetString(TEXT("/Script/DiscordGameSDK.DiscordGameSDKSettings"), TEXT("DevelopmentClientID"), RawClientID, GGameIni);
	GConfig->GetString(TEXT("/Script/DiscordGameSDK.DiscordGameSDKSettings"), TEXT("DevelopmentCreateFlag"), RawCreateFlag, GGameIni);
	const FString EngineVersion = FString::Format(TEXT("Engine Version: {0}.{1}.{2}"), TArray<FStringFormatArg>{ ENGINE_MAJOR_VERSION, ENGINE_MINOR_VERSION, ENGINE_PATCH_VERSION });

	uint64 ClientID = FCString::Strtoui64(*RawClientID, NULL, 10);
	ECreateFlags CreateFlag = FStringToCreateFlags(RawCreateFlag);
	
	discord::Result Result = discord::Core::Create(ClientID, (uint64_t)CreateFlag, &CoreInstance);
	Activity.SetDetails("");
	Activity.SetState("");
	Activity.GetAssets().SetLargeText(TCHAR_TO_ANSI(*ProjectName));
	Activity.GetAssets().SetSmallImage("ue_black");
	Activity.GetAssets().SetSmallText(TCHAR_TO_ANSI(*EngineVersion));
#else
	FText DefaultDetails;
	FText DefaultState;

	GConfig->GetString(TEXT("/Script/DiscordGameSDK.DiscordGameSDKSettings"), TEXT("GameClientID"), RawClientID, GGameIni);
	GConfig->GetString(TEXT("/Script/DiscordGameSDK.DiscordGameSDKSettings"), TEXT("GameCreateFlag"), RawCreateFlag, GGameIni);
	GConfig->GetText(TEXT("/Script/DiscordGameSDK.DiscordGameSDKSettings"), TEXT("DefaultDetails"), DefaultDetails, GGameIni);
	GConfig->GetText(TEXT("/Script/DiscordGameSDK.DiscordGameSDKSettings"), TEXT("DefaultState"), DefaultState, GGameIni);

	uint64 ClientID = FCString::Strtoui64(*RawClientID, NULL, 10);
	ECreateFlags CreateFlag = FStringToCreateFlags(RawCreateFlag);

	discord::Result Result = discord::Core::Create(ClientID, (uint64_t)CreateFlag, &CoreInstance);
	Activity.SetDetails(TCHAR_TO_ANSI(*DefaultDetails.ToString()));
	Activity.SetState(TCHAR_TO_ANSI(*DefaultState.ToString()));
#endif

	if (Result != discord::Result::Ok || CoreInstance == nullptr) UE_LOG(LogDiscord, Error, TEXT("Failed to create Discord Core"));

	Activity.SetType(discord::ActivityType::Playing);
	Activity.GetTimestamps().SetStart(Time);
	GConfig->GetString(TEXT("/Script/DiscordGameSDK.DiscordGameSDKSettings"), TEXT("DefaultLogo"), DefaultLogo, GGameIni);
	Activity.GetAssets().SetLargeImage(TCHAR_TO_ANSI(*DefaultLogo));

	if (CoreInstance) CoreInstance->ActivityManager().UpdateActivity(Activity, [](discord::Result Result) {});
#endif
}

void FDiscordGameSDKModule::UpdateFocusedWindowStatus()
{
#if WITH_EDITOR
	if (GEditor)
	{
		UAssetEditorSubsystem* AssetEditorSubsystem;
		TArray<UObject*> EditedAssets;
		TArray<IAssetEditorInstance*> OpenedEditors;
		IAssetEditorInstance* FocusedEditor;

		FString EditorName = "Level Editor";
		FString FileName = GLevelEditorModeTools().GetWorld()->GetMapName();
		double MaxLastActivationTime = 0.0;

		AssetEditorSubsystem = GEditor->GetEditorSubsystem<UAssetEditorSubsystem>();
		EditedAssets = AssetEditorSubsystem->GetAllEditedAssets();
		OpenedEditors.Empty();
		FocusedEditor = nullptr;

		for (UObject* EditedAsset : EditedAssets) OpenedEditors.Add(AssetEditorSubsystem->FindEditorForAsset(EditedAsset, false));

		for (IAssetEditorInstance* OpenedEditor : OpenedEditors)
		{
			if (OpenedEditor && OpenedEditor->GetLastActivationTime() > MaxLastActivationTime)
			{
				MaxLastActivationTime = OpenedEditor->GetLastActivationTime();
				FocusedEditor = OpenedEditor;
			}
		}

		if (FocusedEditor)
		{
			EditorName = GetFriendlyEditorName(FocusedEditor->GetEditorName());
			FileName = FocusedEditor->GetAssociatedTabManager()->GetOwnerTab()->GetTabLabel().ToString();
		}

		Activity.SetDetails(TCHAR_TO_ANSI(*EditorName));
		Activity.SetState(TCHAR_TO_ANSI(*FileName));

		CoreInstance->ActivityManager().UpdateActivity(Activity, [](discord::Result Result) {});
	}
#endif
}

#undef LOCTEXT_NAMESPACE
IMPLEMENT_MODULE(FDiscordGameSDKModule, DiscordGameSDK)
