// Copyright 2020 NIRV Team LLC. All Rights Reserved.
//
#include "Character/NIRVPlayerCharacter.h"

#include <Camera/CameraComponent.h>
#include <Components/CapsuleComponent.h>
#include <GameFramework/CharacterMovementComponent.h>
#include "Character/NIRVCharacter.h"
#include "Core/NIRVGameInstance.h"


ANIRVPlayerCharacter::ANIRVPlayerCharacter()
{
	Character = CreateDefaultSubobject<UNIRVCharacter>(TEXT("Character"));
	Character->FirstName = "Octavia";
	Character->LastName = "Rein";

	Character->Armour = 10.f;

	GetCapsuleComponent()->InitCapsuleSize(20.f, 90.f);

	FirstPersonHorizontalSensitivity = 40.f;
	FirstPersonVerticalSensitivity = 40.f;

	GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -90.f));
	GetMesh()->SetRelativeRotation(FRotator(0.f, 270.f, 0.f));

	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCamera->bUsePawnControlRotation = true;
	FirstPersonCamera->FieldOfView = 92.0f;
	
	Character->MaxWalkSpeed = 200.f;
	Character->MaxRunSpeed = 300.f;
	Character->MaxSprintSpeed = 400.f;
	Character->MaxCrouchSpeed = 100.f;

	GetCharacterMovement()->MaxWalkSpeed = Character->MaxWalkSpeed;
	GetCharacterMovement()->GravityScale = 1.6f;
	GetCharacterMovement()->JumpZVelocity = 500.f;
	GetCharacterMovement()->AirControl = 0.9f;
	GetCharacterMovement()->AirControlBoostMultiplier = 0.f;
	GetCharacterMovement()->AirControlBoostVelocityThreshold = 0.f;
}

void ANIRVPlayerCharacter::SetupPlayerInputComponent(class UInputComponent* InPlayerInputComponent)
{
	Super::SetupPlayerInputComponent(InPlayerInputComponent);
	check(InPlayerInputComponent);

	InPlayerInputComponent->BindAxis("MoveX", this, &ANIRVPlayerCharacter::MoveX);
	InPlayerInputComponent->BindAxis("MoveY", this, &ANIRVPlayerCharacter::MoveY);

	InPlayerInputComponent->BindAxis("LookX", this, &ANIRVPlayerCharacter::LookX);
	InPlayerInputComponent->BindAxis("LookY", this, &ANIRVPlayerCharacter::LookY);

	InPlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ANIRVPlayerCharacter::Jump);
	InPlayerInputComponent->BindAction("Jump", IE_Released, this, &ANIRVPlayerCharacter::StopJumping);

	InPlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &ANIRVPlayerCharacter::StartCrouch);
	InPlayerInputComponent->BindAction("Crouch", IE_Released, this, &ANIRVPlayerCharacter::StartWalk);

	InPlayerInputComponent->BindAction("Run", IE_Pressed, this, &ANIRVPlayerCharacter::StartRun);
	InPlayerInputComponent->BindAction("Run", IE_Released, this, &ANIRVPlayerCharacter::StartWalk);
	InPlayerInputComponent->BindAction("Run", IE_DoubleClick, this, &ANIRVPlayerCharacter::StartSprint);

	InPlayerInputComponent->BindAction("QuickMenu", IE_Pressed, this, &ANIRVPlayerCharacter::ShowQuickMenu);
	InPlayerInputComponent->BindAction("QuickMenu", IE_Released, this, &ANIRVPlayerCharacter::HideQuickMenu);

	InPlayerInputComponent->BindAction("Pause", IE_Pressed, this, &ANIRVPlayerCharacter::ToggleGameMenu);

	InPlayerInputComponent->BindAction("MouseWheelUp", IE_Pressed, this, &ANIRVPlayerCharacter::ScrollUp);
	InPlayerInputComponent->BindAction("MouseWheelDown", IE_Pressed, this, &ANIRVPlayerCharacter::ScrollDown);
}

void ANIRVPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	UIManager = Cast<AUIManager>(GetWorld()->GetFirstPlayerController()->GetHUD());

	FirstPersonCamera->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("head"));
	FirstPersonCamera->SetRelativeLocation(FVector(5.f, 10.f, 0.f));

	GetWorld()->GetFirstPlayerController()->PlayerCameraManager->ViewPitchMin = -80.f;
	GetWorld()->GetFirstPlayerController()->PlayerCameraManager->ViewPitchMax = 80.f;

	UIManager->ShowGameHUD();
}

void ANIRVPlayerCharacter::Tick(float InDeltaTime) { Super::Tick(InDeltaTime); }

void ANIRVPlayerCharacter::MoveX(const float InValue)
{
	if (IsGamePaused()) return;

	if (InValue != 0.f) AddMovementInput(GetActorRightVector(), InValue);
}

void ANIRVPlayerCharacter::MoveY(const float InValue)
{
	if (IsGamePaused()) return;

	if (InValue != 0.f) AddMovementInput(GetActorForwardVector(), InValue);
}

void ANIRVPlayerCharacter::LookX(const float InValue)
{
	if (IsGamePaused()) return;

	AddControllerYawInput(InValue * FirstPersonHorizontalSensitivity * GetWorld()->GetDeltaSeconds());
}

void ANIRVPlayerCharacter::LookY(const float InValue)
{
	if (IsGamePaused()) return;

	AddControllerPitchInput(InValue * FirstPersonVerticalSensitivity * GetWorld()->GetDeltaSeconds());
}

void ANIRVPlayerCharacter::StartWalk()
{
	if (Character->MovementInformation.bCanWalk)
	{
		if (Character->MovementInformation.CurrentTerrestrialMovementState == ETerrestrialMovementState::Crouching)
		{
			bIsCrouched = false;
			CrouchedEyeHeight = BaseEyeHeight;
			RecalculateBaseEyeHeight();
		}

		GetCharacterMovement()->MaxWalkSpeed = Character->MaxWalkSpeed;
		Character->MovementInformation.CurrentTerrestrialMovementState = ETerrestrialMovementState::Walking;
	}
}

void ANIRVPlayerCharacter::StartRun()
{
	if (Character->MovementInformation.bCanRun)
	{
		GetCharacterMovement()->MaxWalkSpeed = Character->MaxRunSpeed;
		Character->MovementInformation.CurrentTerrestrialMovementState = ETerrestrialMovementState::Running;
	}
}

void ANIRVPlayerCharacter::StartSprint()
{
	if (Character->MovementInformation.bCanSprint)
	{
		GetCharacterMovement()->MaxWalkSpeed = Character->MaxSprintSpeed;
		Character->MovementInformation.CurrentTerrestrialMovementState = ETerrestrialMovementState::Sprinting;
	}
}

void ANIRVPlayerCharacter::StartCrouch()
{
	if (Character->MovementInformation.bCanCrouch)
	{
		bIsCrouched = true;
		CrouchedEyeHeight = BaseEyeHeight / 4;
		RecalculateBaseEyeHeight();

		GetCharacterMovement()->MaxWalkSpeed = Character->MaxCrouchSpeed;
		Character->MovementInformation.CurrentTerrestrialMovementState = ETerrestrialMovementState::Crouching;
	}
}
