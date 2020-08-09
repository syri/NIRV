// Copyright 2020 NIRV Team LLC. All Rights Reserved.
//
#pragma once
#include <CoreMinimal.h>
#include <MoviePlayer.h>
#include <Widgets/Layout/SScaleBox.h>

#include "LoadingScreenSettings.generated.h"


/**
 * NIRV Loading Screen Settings.
 */
USTRUCT(BlueprintType)
struct NIRV_API FLoadingScreenDescription
{
	GENERATED_BODY()

	/** The minimum time that a loading screen should be opened for, -1 if there is no minimum time. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loading")
	float MinimumLoadingScreenDisplayTime = -1;

	/** If true, the loading screen will disappear as soon as loading is done. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loading")
	bool bAutoCompleteWhenLoadingCompletes = true;

	/** The texture to display while in the loading screen. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Images", meta = (AllowedClasses = "Texture2D,Material,MaterialInstance"))
	FSoftObjectPath LoadingImage;

	/** The scaling type to apply to images. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Images")
	TEnumAsByte<EStretch::Type> ImageStretch = EStretch::ScaleToFit;

	/** The background color to use. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Images")
	FLinearColor BackgroundColor = FLinearColor::Black;

};

/**
 * NIRV Loading Screen settings.
 */
UCLASS(config = Game, defaultconfig, meta = (DisplayName = "Loading Screen"))
class NIRV_API ULoadingScreenSettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:
	/** The startup screen for the project. */
	UPROPERTY(config, EditAnywhere, Category = "Screens")
	FLoadingScreenDescription StartupScreen;

	/** The default load screen between maps. */
	UPROPERTY(config, EditAnywhere, Category = "Screens")
	FLoadingScreenDescription DefaultScreen;

	/** The font to display while loading. */
	UPROPERTY(config, EditAnywhere, BlueprintReadWrite, Category = "Display")
	FSlateFontInfo RedistributionWarningFont;

public:
	ULoadingScreenSettings();

};
