// Copyright 2020 NIRV Team LLC. All Rights Reserved.
//
#include "Core/NIRVGameInstance.h"

#include "Interface/SLoadingScreen.h"
#include "Utility/NIRVWindowsLibrary.h"


void UNIRVGameInstance::Init()
{
	// Load for cooker reference.
	const ULoadingScreenSettings* Settings = GetDefault<ULoadingScreenSettings>();
	const FStringAssetReference& LoadingImageRef = Settings->StartupScreen.LoadingImage;
	LoadingImageRef.TryLoad();
	
	if (IsMoviePlayerEnabled())
		GetMoviePlayer()->OnPrepareLoadingScreen().AddUObject(this, &UNIRVGameInstance::HandlePrepareLoadingScreen);

	BeginLoadingScreen(Settings->StartupScreen);
}

void UNIRVGameInstance::Shutdown()
{
	if (!IsRunningDedicatedServer())
		GetMoviePlayer()->OnPrepareLoadingScreen().RemoveAll(this);

	if (UNIRVWindowsLibrary::IsCapsLockEnabled()) UNIRVWindowsLibrary::SetCapsLockState(false);
}

void UNIRVGameInstance::HandlePrepareLoadingScreen()
{
	const ULoadingScreenSettings* Settings = GetDefault<ULoadingScreenSettings>();
	BeginLoadingScreen(Settings->DefaultScreen);
}

void UNIRVGameInstance::BeginLoadingScreen(const FLoadingScreenDescription& InScreenDescription)
{
	FLoadingScreenAttributes LoadingScreen;
	LoadingScreen.MinimumLoadingScreenDisplayTime = InScreenDescription.MinimumLoadingScreenDisplayTime;
	LoadingScreen.bAutoCompleteWhenLoadingCompletes = InScreenDescription.bAutoCompleteWhenLoadingCompletes;

	LoadingScreen.WidgetLoadingScreen = SNew(SNIRVLoadingScreen, InScreenDescription);
	
	GetMoviePlayer()->SetupLoadingScreen(LoadingScreen);
}
