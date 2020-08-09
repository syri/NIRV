// Copyright 2020 NIRV Team LLC. All Rights Reserved.
//
#pragma once
#include <CoreMinimal.h>
#include "DiscordTypes.h"
#include <Engine/DeveloperSettings.h>

#include "DiscordGameSDKSettings.generated.h"


/**
 * Discord Game SDK Screen settings.
 */
UCLASS(config = Game, defaultconfig, meta = (DisplayName = "Discord Game SDK"))
class UDiscordGameSDKSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(config, EditAnywhere, Category = "Application")
	uint64 DevelopmentClientID = 461618159171141643;

	UPROPERTY(config, EditAnywhere, Category = "Application")
	ECreateFlags DevelopmentCreateFlag = ECreateFlags::Default;

	UPROPERTY(config, EditAnywhere, Category = "Application")
	uint64 GameClientID = 461618159171141643;

	UPROPERTY(config, EditAnywhere, Category = "Application")
	ECreateFlags GameCreateFlag = ECreateFlags::Default;

	UPROPERTY(config, EditAnywhere, BlueprintReadWrite, Category = "Default Activity")
	FText DefaultDetails = FText::FromString(TEXT("Default Details"));

	UPROPERTY(config, EditAnywhere, BlueprintReadWrite, Category = "Default Activity")
	FText DefaultState = FText::FromString(TEXT("Default State"));

	UPROPERTY(config, EditAnywhere, BlueprintReadWrite, Category = "Default Activity")
	FString DefaultLogo = TEXT("default-logo");

public:
	UDiscordGameSDKSettings();

};