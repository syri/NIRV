// Copyright 2020 NIRV Team LLC. All Rights Reserved.
//
#include "Character/NIRVCharacter.h"


UNIRVCharacter::UNIRVCharacter()
{
	// Default Movement Data.
	//
	MaxWalkSpeed = 200.f;
	MaxRunSpeed = 450.f;
	MaxSprintSpeed = 650.f;
	MaxCrouchSpeed = 100.f;
	MovementInformation = FMovementInformation();

	// Default Personal Information.
	//
	FirstName = "Unknown";
	LastName = "Unknown";
	Nickname = "Unknown";
	bUseFullname = true;
	bUseNickname = false;

	// Default Battle Information
	//
	Armour = 0;
	bIsDead = false;
	bIsOutOfAction = false;

	Vitality = 20;
	Strength = 1;
	Intelligence = 1;
	CriticalHit = 1;

	GetMaxHealth();
	CurrentHealth = MaxHealth;
	MinimumHealth = 0;

	// Default Personality Information.
	//
	Willpower = 10;
	Charisma = 10;
	PersonalityType = FPersonalityType();

	// Default Character Appearance.
	//
	// General
	Height = 170.0f;
	WaistThickness = 4.0f;
	LegThickness = 4.0f;
	HipSize = 1.0f;
	ButtSize = 1.0f;

	MuscleTone = 5.0f;
	Femininity = 8;
	SkinType = ESkinType::Skin;
	SkinTone = FColor().White;
	FurColour = FColor().White;
	ScaleColour = FColor().White;
	// Head
	EarType = EEarType::Human;
	EarLength = 2.0f;
	HornType = EHornType::None;
	HornCount = 0;
	HornLength = 0.0f;
	// Hair
	HairType = EHairType::Hair;
	HairColour = FColor().White;
	HairLength = 30.0f;
	HairStyle = EHairStyle::Ponytail;
	BeardType = EBeardType::Hair;
	BeardLength = 0.0f;
	BeardStyle = EBeardStyle::None;
	// Face
	FaceType = EFaceType::Human;
	EyeType = EEyeType::Human;
	EyeColour = FColor().White;
	TongueType = ETongueType::Human;
	LipColour = FColor().White;
	LipSize = 1.0f;
	// Arms
	ArmType = EArmType::Human;
	ArmLength = 1.0f;
	// Legs
	LegType = ELegType::Human;
	LegLength = 1.0f;
	// Tail
	TailType = ETailType::None;
	TailCount = 0;
	// Wings
	WingType = EWingType::None;
	WingCount = 0;
}
