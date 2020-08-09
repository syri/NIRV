// Copyright 2020 NIRV Team LLC. All Rights Reserved.
//
#pragma once
#include <CoreMinimal.h>
#include <GameFramework/GameModeBase.h>

#include "NIRVGameMode.generated.h"


/**
 * NIRV default gameplay gamemode.
 */
UCLASS(MinimalAPI)
class ANIRVGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	/** Whether or not time is currently slowed. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player|World")
	bool bIsTimeSlowed;

public:
	ANIRVGameMode();

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type InEndPlayReason) override;

	/** Start slow motion for the player. */
	UFUNCTION(BlueprintCallable, Category = "World")
	void StartSlowMotion(const float InValue);

	/** Stop slow motion for the player. */
	UFUNCTION(BlueprintCallable, Category = "World")
	void StopSlowMotion();

};
