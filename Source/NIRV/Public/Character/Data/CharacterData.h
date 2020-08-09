// Copyright 2020 NIRV Team LLC. All Rights Reserved.
//
#pragma once
#include <CoreMinimal.h>
#include "CharacterAppearanceData.h"

#include "CharacterData.generated.h"


/** Available races. */
UENUM(BlueprintType)
enum class ERace : uint8
{
	/** Human race. */
	Human
};

/** Available traits that can be inherited. */
UENUM(BlueprintType)
enum class ETrait : uint8
{
	/** Placeholder trait for testing purposes. */
	Placeholder
};

/** Terrestrial movement states. */
UENUM(BlueprintType)
enum class ETerrestrialMovementState : uint8
{
	Walking,
	Running,
	Sprinting,
	Crouching
};

/** Data structure containing information regarding personality. */
USTRUCT(BlueprintType)
struct FPersonalityType
{
	GENERATED_BODY()

	/** How kind the character is. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Personality")
	float Kindness;
	/** How mean the character is. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Personality")
	float Meanness;
	/** How edgy the character is. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Personality")
	float Edgyness;
	/** How mischievous the character is. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Personality")
	float Mischievousness;

	FPersonalityType(const float InKindness = 20.0f, const float InMeanness = 0.0f, const float InEdgyness = 0.0f, const float InMischievousness = 0.0f)
		: Kindness(InKindness), Meanness(InMeanness), Edgyness(InEdgyness), Mischievousness(InMischievousness)
	{}

};

/** Data structure containing information regarding the character's movement. */
USTRUCT(BlueprintType)
struct FMovementInformation
{
	GENERATED_BODY()

	/** Current terrestrial movement state. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Movement")
	ETerrestrialMovementState CurrentTerrestrialMovementState;

	/** Is the character crouching. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Movement")
	bool bIsCrouching;

	/** Is the character swimming. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Movement")
	bool bIsSwimming;

	/** Can the character walk? */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Movement")
	bool bCanWalk;
	/** Can the character run? */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Movement")
	bool bCanRun;
	/** Can the character sprint? */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Movement")
	bool bCanSprint;

	/** Can the character jump? */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Movement")
	bool bCanJump;
	/** Can the character crouch? */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Movement")
	bool bCanCrouch;
	/** Can the character swim? */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Movement")
	bool bCanSwim;

	FMovementInformation()
		: CurrentTerrestrialMovementState(ETerrestrialMovementState::Walking)
		, bIsCrouching(false), bIsSwimming(false)
		, bCanWalk(true), bCanRun(true), bCanSprint(true)
		, bCanJump(true), bCanCrouch(true), bCanSwim(true)
	{}

};
