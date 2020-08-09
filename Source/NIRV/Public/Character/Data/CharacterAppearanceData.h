// Copyright 2020 NIRV Team LLC. All Rights Reserved.
//
#pragma once
#include <CoreMinimal.h>

#include "CharacterAppearanceData.generated.h"


/** Available skin types. */
UENUM(BlueprintType)
enum class ESkinType : uint8
{
	/** Plain human-like skin. */
	Skin,
	/** Fur that covers human-like skin. */
	Fur,
	/** Scales that covers human-like skin. */
	Scales,
	/** Goo-like body. */
	Goo,
	/** Feathers that covers human-like skin. */
	Feathers,
	/** Latex that covers the body. */
	Latex
};

/** Additional flags that can be applied to skin. */
UENUM(BlueprintType)
enum class ESkinFlag : uint8
{
	Lubricated,
	Fluffy,
	Squishy,
	Smooth,
	Sticky,
	Thick,
	Amorphous,
	Furred,
	Scaled,
	Feathered,
	Gooey,
	Abosrbent,
	Freckled,
	PartiallyScaled
};

/** Available type of hair that is applied to the head. */
UENUM(BlueprintType)
enum class EHairType : uint8
{
	None,
	Hair,
	Feathers,
	Transparent,
	Gooey
};

/** Available hair styles. Only applicable if the hair type is styeable. */
UENUM(BlueprintType)
enum class EHairStyle : uint8
{
	Ponytail,
	Straight
};

/** Available ear types. */
UENUM(BlueprintType)
enum class EEarType : uint8
{
	Human
};

/** Additional flags that can be applied to ears. */
UENUM(BlueprintType)
enum class EEarFlag : uint8
{
	Long,
	Tapered,
	Furred,
	Floppy
};

/** Available horn types */
UENUM(BlueprintType)
enum class EHornType : uint8
{
	None,
	Demon
};

/** Available face types */
UENUM(BlueprintType)
enum class EFaceType : uint8
{
	Human
};

/** Additional flags that can be applied to faces. */
UENUM(BlueprintType)
enum class EFaceFlag : uint8
{
	Long,
	Smooth,
	Muzzled,
	Angular,
	Furred,
	Beak,
	Freckled
};

/** Available types of eyes. */
UENUM(BlueprintType)
enum class EEyeType : uint8
{
	Human
};

/** Available types of tongues. */
UENUM(BlueprintType)
enum class ETongueType : uint8
{
	Human
};

/** Additional flags that can be applied to tongues. */
UENUM(BlueprintType)
enum class ETongueFlag : uint8
{
	Long,
	Tapered,
	Sticky,
	Nubby,
	Gooey
};

/** Available types of beards. */
UENUM(BlueprintType)
enum class EBeardType : uint8
{
	None,
	Hair,
	Feathers,
	Transparent,
	Gooey
};

/** Available beard styles. Only applicable when beard isn't of type; None. */
UENUM(BlueprintType)
enum class EBeardStyle : uint8
{
	None
};

/** Available arm types. */
UENUM(BlueprintType)
enum class EArmType : uint8
{
	Human
};

/** Additional flags that can be applied to arms. */
UENUM(BlueprintType)
enum class EArmFlag : uint8
{
	Long,
	Fluffy,
	Smooth,
	Thick,
	Amorphous,
	Furred,
	Scaled,
	Hooves,
	Paws,
	Feathered,
	Gooey
};

/** Available leg types. */
UENUM(BlueprintType)
enum class ELegType : uint8
{
	Human
};

/** Additional flags that can be applied to legs. */
UENUM(BlueprintType)
enum class ELegFlag : uint8
{
	Long,
	Fluffy,
	Smooth,
	Thick,
	Plantigrade,
	Digitgrade,
	Amorphous,
	Furred,
	Scaled,
	Hooves,
	Paws,
	Feathered,
	Gooey
};

/** Available tail types. */
UENUM(BlueprintType)
enum class ETailType : uint8
{
	None,
	Demon
};

/** Additional flags that can be applied to tails. */
UENUM(BlueprintType)
enum class ETailFlag : uint8
{
	Long,
	Fluffy,
	Squishy,
	Smooth,
	Tapered,
	Blunt,
	Thick,
	Furred,
	Stinger,
	Nubby,
	Ribbed,
	Feathered,
	Gooey,
	PartiallyScaled,
	Short,
	Floppy
};

/** Available types of wings. */
UENUM(BlueprintType)
enum class EWingType : uint8
{
	None,
	Demon
};

/** Additional flags that can be applied to breasts. */
UENUM(BlueprintType)
enum class EBreastFlag : uint8
{
	Normal
};

/** Data structure containing information regarding a specific row of breasts. */
USTRUCT(BlueprintType)
struct FBreastRow
{
	GENERATED_BODY()

	/** Size of the breasts. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|Body")
	float Size;
	/** Additional display and mechanic flags for the row of breasts. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|Body")
	TArray<EBreastFlag> Flags;

	FBreastRow(const float InSize = 1.0f)
		: Size(InSize)
	{}

};
