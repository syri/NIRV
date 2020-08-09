// Copyright 2020 NIRV Team LLC. All Rights Reserved.
//
#pragma once
#include <CoreMinimal.h>
#include <Blueprint/UserWidget.h>
#include <GameFramework/Character.h>
#include "Interface/UIManager.h"

#include "NIRVPlayerCharacter.generated.h"


/**
 * NIRV Player Character.
 */
UCLASS()
class NIRV_API ANIRVPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	/** First person camera horizontal sensitivity. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player|Camera")
	float FirstPersonHorizontalSensitivity;

	/** First person camera vertical sensitivity. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player|Camera")
	float FirstPersonVerticalSensitivity;

protected:
	/** First person camera. */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FirstPersonCamera;

	/** Personal Attributes. */
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Character", meta = (AllowPrivateAccess = "true"))
	class UNIRVCharacter* Character;

private:
	AUIManager* UIManager;

public:
	ANIRVPlayerCharacter();

	virtual void BeginPlay() override;
	virtual void Tick(float InDeltaTime) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	/** Get the player's first person camera. */
	UFUNCTION(BlueprintGetter, Category = "Player")
	FORCEINLINE class UCameraComponent* GetFirstPersonCamera() const { return FirstPersonCamera; }

	/** Get the player's character object. */
	UFUNCTION(BlueprintGetter, Category = "Player")
	FORCEINLINE class UNIRVCharacter* GetCharacter() const { return Character; }

	/** Forward function to UIManager. */
	UFUNCTION()
	void ToggleGameMenu() { UIManager->ToggleGameMenu(); }

	/** Forward function to UIManager. */
	UFUNCTION()
	void ToggleGameHUD() { UIManager->ToggleGameHUD(); }

	/** Forward function to UIManager. */
	UFUNCTION()
	void ShowQuickMenu() { UIManager->ShowQuickMenu(); }

	/** Forward function to UIManager. */
	UFUNCTION()
	void HideQuickMenu() { UIManager->HideQuickMenu(); }

	UFUNCTION()
	void ScrollUp() { UIManager->ScrollUp(); }

	UFUNCTION()
	void ScrollDown() { UIManager->ScrollDown(); }

protected:
	/** Handles moving along X axis. */
	UFUNCTION()
	void MoveX(const float InValue);

	/** Handles moving along Y axis. */
	UFUNCTION()
	void MoveY(const float InValue);

	/**
	 * Handles camera rotation along X axis.
	 * @param Value	is normalised; 1.0 = 100%
	 */
	UFUNCTION()
	void LookX(const float InValue);

	/**
	 * Handles camera rotation along Y axis.
	 * @param Value	is normalised; 1.0 = 100%
	 */
	UFUNCTION()
	void LookY(const float InValue);

	/**
	 * Handle the player as they try to crouch.
	 */
	UFUNCTION(BlueprintCallable, Category = "Player|Movement")
	void StartCrouch();

	/** Handle the player as they try to walk. */
	UFUNCTION(BlueprintCallable, Category = "Player|Movement")
	void StartWalk();

	/** 
	 * Handle the player as they try to run.
	 * Double tapping starts a sprint.
	 */
	UFUNCTION(BlueprintCallable, Category = "Player|Movement")
	void StartRun();

	/** Handle the player as they try to sprint. */
	UFUNCTION(BlueprintCallable, Category = "Player|Movement")
	void StartSprint();

	/** Check if the game is paused. */
	FORCEINLINE bool IsGamePaused() { return UIManager->GameMenuReference && UIManager->GameMenu && UIManager->GameMenu->IsVisible(); }

};
