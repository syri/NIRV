// Copyright 2020 NIRV Team LLC. All Rights Reserved.
//
#pragma once
#include <CoreMinimal.h>
#include "Data/CharacterData.h"

#include "NIRVCharacter.generated.h"


/**
 * NIRV Character.
 * Component that describes a person, their attributed, and their behaviours.
 */
UCLASS(Blueprintable, ClassGroup = Character)
class NIRV_API UNIRVCharacter : public UActorComponent
{
	GENERATED_BODY()

public:
	// Movement
	//
	/** Maximum movement speed while walking. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Movement")
	float MaxWalkSpeed;

	/** Maximum movement speed while running. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Movement")
	float MaxRunSpeed;

	/** Maximum movement speed while sprinting. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Movement")
	float MaxSprintSpeed;

	/** Maximum movement speed while crouching. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Movement")
	float MaxCrouchSpeed;

	/** Holds the current movement information for the character. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Movement")
	FMovementInformation MovementInformation;

	// Personal Information
	//
	/** Character's first name. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Information")
	FString FirstName;
	/** Character's last name. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Information")
	FString LastName;
	/** Character's nickname. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Information")
	FString Nickname;
	/** Whether or not to display the character's full name in dialogue. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Information")
	bool bUseFullname;
	/** Whether or not to display the character's nickname in dialogue. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Information")
	bool bUseNickname;
	/** Character's race. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Information")
	ERace Race;

	// Progression Information
	//
	/** Character's level. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Progression")
	int32 Level;
	/** Character's current experience points. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Progression")
	int32 ExperiencePoints;
	/** Array of all traits that the character has. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Progression")
	TArray<ETrait> Traits;

	// Health Information
	//
	/** Max health for the character. */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, BlueprintGetter = GetMaxHealth, Category = "Character|Battle")
	float MaxHealth;
	/** Current health for the character. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Battle")
	float CurrentHealth;
	/** Minimum health for the character before being considered dead or incapacitated. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Battle")
	float MinimumHealth;
	/** Current armour amount for the character. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Battle")
	float Armour;
	/** Is the character dead. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Battle")
	bool bIsDead;
	/** Is the character incapacitated. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Battle")
	bool bIsOutOfAction;

	// Battle Attributes
	//
	/** Vitality stat. Affects health and defense. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Battle")
	int32 Vitality;
	/** Strength stat. Affects physical-based mechanics. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Battle")
	int32 Strength;
	/** Intelligence stat. Affects magical-based mechanics. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Battle")
	int32 Intelligence;
	/** Dexterity stat. Affects movement and dodge chance. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Battle")
	int32 Dexterity;
	/** Critical Hit. Affects chance of critical hits and their power. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Battle")
	int32 CriticalHit;

	// Personality
	//
	/** Character's ability to withstand certain situations. */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Character|Personality")
	int32 Willpower;
	/** Character's influence on other characters. */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Character|Personality")
	int32 Charisma;
	/** Character's personality type based on (Kindness, Meanness, Edgyness, Mischievousness) */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Character|Personality")
	FPersonalityType PersonalityType;
	
	// Appearance
	//

	// General Body Shape
	//
	/** Height of the character. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|General Shape")
	float Height;
	/** Character's waist thickness. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|General Shape")
	float WaistThickness;
	/** Character's leg thickness. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|General Shape")
	float LegThickness;
	/** Character's hip size. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|Body")
	float HipSize;
	/** Character's butt size. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|Body")
	float ButtSize;

	/** How muscular the character is. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|General Shape")
	int32 MuscleTone;
	/** How feminine the character is. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|General Shape")
	int32 Femininity;
	/** Character's skin type. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|General Shape")
	ESkinType SkinType;
	/** Character's skin tone. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|General Shape")
	FColor SkinTone;
	/** Additional display and mechanic flags for the character's skin. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|General Shape")
	TArray<ESkinFlag> SkinFlags;
	/** Character's fur colour if they have any. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|General Shape")
	FColor FurColour;
	/** Character's scale colour if they have any. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|General Shape")
	FColor ScaleColour;

	// Head
	//
	/** Character's ear type. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|Head")
	EEarType EarType;
	/** Character's ear length. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|Head")
	float EarLength;
	/** Additional display and mechanic flags for the character's ears. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|Head")
	TArray<EEarFlag> EarFlags;
	/** Character's horn type. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|Head")
	EHornType HornType;
	/** Character's horn count. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|Head")
	int32 HornCount;
	/** Character's horn length. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|Head")
	float HornLength;
	// Hair
	/** Character's hair type if they have any. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|Head")
	EHairType HairType;
	/** Character's hair colour if they have any. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|Head")
	FColor HairColour;
	/** Character's hair length if they have any. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|Head")
	float HairLength;
	/** Character's hair style. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|Head")
	EHairStyle HairStyle;
	/** Character's beard type if they have one. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|Head")
	EBeardType BeardType;
	/** Character's beard length if they have one. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|Head")
	float BeardLength;
	/** Character's beard style. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|Head")
	EBeardStyle BeardStyle;
	// Face
	/** Character's face type. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|Head")
	EFaceType FaceType;
	/** Additional display and mechanic flags for the character's face. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|Head")
	TArray<EFaceFlag> FaceFlags;
	/** Character's eye type. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|Head")
	EEyeType EyeType;
	/** Character's eye colour. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|Head")
	FColor EyeColour;
	/** Character's tongue type. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|Head")
	ETongueType TongueType;
	/** Additional display and mechanic flags for character's tongue. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|Head")
	TArray<ETongueFlag> TongueFlags;
	/** Character's lip colour. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|Head")
	FColor LipColour;
	/** Character's lip size. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|Head")
	float LipSize;

	// Body
	//
	// Arms
	/** Character's arm type. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|Body")
	EArmType ArmType;
	/** Character's arm length. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|Body")
	float ArmLength;
	/** Additional display and mechanic flags for character's arms. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|Body")
	TArray<EArmFlag> ArmFlags;
	// Legs
	/** Character's leg type. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|Body")
	ELegType LegType;
	/** Character's leg length. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|Body")
	float LegLength;
	/** Additional display and mechanic flags for character's legs. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|Body")
	TArray<ELegFlag> LegFlags;
	// Chest
	/** Array of the character's breasts */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|Body")
	TArray<FBreastRow> BreastRows;
	// Tail
	/** Character's tail type. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|Body")
	ETailType TailType;
	/** Amount of tails the character has. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|Body")
	int32 TailCount;
	/** Additional display and mechanic flags for the character's tail. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|Body")
	TArray<ETailFlag> TailFlags;
	// Wings
	/** Character's wing type. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|Body")
	EWingType WingType;
	/** Amount of wings the character has. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Appearance|Body")
	int32 WingCount;

private:
	/** Power of physical based attacks. */
	UPROPERTY(EditAnywhere, BlueprintGetter = GetPhysicalAttackPower, Category = "Character|Battle")
	float PhysicalAttackPower;
	/** Power of magical based attacks. */
	UPROPERTY(EditAnywhere, BlueprintGetter = GetMagicalAttackPower, Category = "Character|Battle")
	float MagicalAttackPower;
	/** Amount of defense against physical damage. */
	UPROPERTY(EditAnywhere, BlueprintGetter = GetPhysicalDefense, Category = "Character|Battle")
	float PhysicalDefense;
	/** Amount of defense against magical damage. */
	UPROPERTY(EditAnywhere, BlueprintGetter = GetMagicalDefense, Category = "Character|Battle")
	float MagicalDefense;
	/** Effectiveness of health regeneration. */
	UPROPERTY(EditAnywhere, BlueprintGetter = GetHealPower, Category = "Character|Battle")
	float HealPower;

public:
	UNIRVCharacter();

	/** Get physical max health for the character. */
	UFUNCTION(BlueprintGetter, Category = "Character|Battle")
	FORCEINLINE float GetMaxHealth() { MaxHealth = Vitality * 5; return MaxHealth; };

	/** Get physical attack power for the character. */
	UFUNCTION(BlueprintGetter, Category = "Character|Battle")
	FORCEINLINE float GetPhysicalAttackPower() { PhysicalAttackPower = Strength * (CriticalHit * 2); return PhysicalAttackPower; };

	/** Get magical attack power for the character. */
	UFUNCTION(BlueprintGetter, Category = "Character|Battle")
	FORCEINLINE float GetMagicalAttackPower() { MagicalAttackPower = Intelligence * (CriticalHit * 2); return MagicalAttackPower; };

	/** Get physical defense for the character. */
	UFUNCTION(BlueprintGetter, Category = "Character|Battle")
	FORCEINLINE float GetPhysicalDefense() { PhysicalDefense = Strength * Vitality; return PhysicalDefense; };

	/** Get magical defense for the character. */
	UFUNCTION(BlueprintGetter, Category = "Character|Battle")
	FORCEINLINE float GetMagicalDefense() { MagicalDefense = Intelligence * Vitality; return MagicalDefense; };

	/** Get heal power for the character. */
	UFUNCTION(BlueprintGetter, Category = "Character|Battle")
	FORCEINLINE float GetHealPower() { HealPower = Intelligence * (CriticalHit * 1.5); return HealPower; };

};
