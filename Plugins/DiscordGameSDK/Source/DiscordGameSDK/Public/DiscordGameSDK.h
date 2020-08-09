// Copyright 2020 NIRV Team LLC. All Rights Reserved.
//
#pragma once
#include <CoreMinimal.h>
#include "DiscordLibrary.h"


/**
 * NIRV Team's Discord Game SDK Plugin Wrapper.
 */
class FDiscordGameSDKModule : public IModuleInterface
{
public:
	FTickerDelegate TickDelegate;
	FDelegateHandle TickDelegateHandle;
	
	TMap<FName, FString> FriendlyEditorNameMap =
	{
		{ "AnimationEditor", "Animation Editor" },
		{ "AnimationBlueprintEditor", "Animation BP Editor" },
		{ "Behaviour Tree", "Behaviour Tree Editor" },
		{ "BlueprintEditor", "Blueprint Editor" },
		{ "Cascade", "Cascade Editor" },
		{ "CodeEditor", "Code Editor" },
		{ "CompositeCurveTableEditor", "Composite Curve Table Editor" },
		{ "ControlRigEditor", "Control Rig Editor" },
		{ "CurveAssetEditor", "Curve Asset Editor" },
		{ "CurveTableEditor", "Curve Table Editor" },
		{ "DataprepEditor", "Dataprep Editor" },
		{ "DataTableEditor", "Data Table Editor" },
		{ "DestructibleMeshEditor", "Destructible Mesh Editor" },
		{ "DMXEditor", "DMX Editor" },
		{ "Environment Query", "Environment Query Editor" },
		{ "FlipbookEditor", "Flipbook Editor" },
		{ "FontEditor", "Font Editor" },
		{ "GameplayAbilitiesEditor", "Gameplay Abilities Editor" },
		{ "LevelSequenceEditor", "Level Sequence Editor" },
		{ "LevelVariantSetsEditor", "Level Variant Sets Editor" },
		{ "LidarPointCloudEditor", "LIDAR Point Cloud Editor" },
		{ "MaterialEditor", "Material Editor" },
		{ "MaterialInstanceEditor", "Material Instance Editor" },
		{ "Matinee", "Matinee Editor" },
		{ "MediaBundleEditorApp", "Media Bundle Editor" },
		{ "MediaPlayerEditor", "Media Player Editor" },
		{ "MediaPlaylistEditor", "Media Playlist Editor" },
		{ "ModulationSettingsEditor", "Modulation Settings Editor" },
		{ "Niagara", "Niagara Editor" },
		{ "PhysicsAssetEditor", "Physics Asset Editor" },
		{ "PropertyEditor", "Property Editor" },
		{ "GenericAssetEditor", "Generic Asset Editor" },
		{ "SkeletalMeshEditor", "Skeletal Mesh Editor" },
		{ "SkeletonEditor", "Skeleton Editor" },
		{ "SoundClassEditor", "Sound Class Editor" },
		{ "SoundCueEditor", "Sound Cue Editor" },
		{ "SoundSubmixEditor", "Sound Submix Editor" },
		{ "SpriteEditor", "Sprite Editor" },
		{ "StaticMeshEditor", "Static Mesh Editor" },
		{ "StringTableEditor", "String Table Editor" },
		{ "TakePresetEditor", "Take Preset Editor" },
		{ "TemplateSequenceEditor", "Template Sequence Editor" },
		{ "TextureEditor", "Texture Editor" },
		{ "TileMapEditor", "Tile Map Editor" },
		{ "TileSetEditor", "Tile Set Editor" },
		{ "TimecodeSynchronizerEditorApp", "Timecode Synchronizer Editor" },
		{ "TranslationEditor", "Translation Editor" },
		{ "EnumEditor", "Enum Editor" },
		{ "UserDefinedStructureEditor", "User Defined Structure Editor" }
	};

private:
	void* DiscordGameSDKLibraryHandle;
	discord::Activity Activity{};

public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

private:
	virtual bool Tick(float InDeltaTime);
    
    static bool LoadDependency(const FString& InDirectory, const FString& InName, void*& InHandle);
    static void FreeDependency(void*& InHandle);

	void SetupDiscord();

	void UpdateFocusedWindowStatus();
	FORCEINLINE FString GetFriendlyEditorName(const FName InName) const { return FriendlyEditorNameMap.Contains(InName) ? FriendlyEditorNameMap[InName] : FString("Eating a Sandwich"); }

};
