// Copyright 2020 NIRV Team LLC. All Rights Reserved.
//
#pragma once
#include <CoreMinimal.h>
#include <GameFramework/HUD.h>
#include "Core/NIRVGameMode.h"
#include "Interface/NIRVDialogueSystem.h"
#include "Utility/NIRVWindowsLibrary.h"

#include "UIManager.generated.h"


/**
 * NIRV UI Manager.
 */
UCLASS()
class NIRV_API AUIManager : public AHUD
{
	GENERATED_BODY()

public:
	ANIRVGameMode* GameMode;

	/** Time dilation value for slow-mo while using the Quick Menu. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player|World")
	float QuickMenuTimeDilation;

	/** Game Menu widget reference. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<class UUserWidget> GameMenuReference;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	UUserWidget* GameMenu;

	/** HUD widget reference. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<class UUserWidget> HUDReference;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	UUserWidget* HUD;

	/** Quick Menu widget reference. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<class UUserWidget> QuickMenuReference;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	UUserWidget* QuickMenu;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UNIRVDialogueSystem* DialogueSystem;

	UPROPERTY()
	FTimerHandle CapsLockResetTimer;

public:
	AUIManager();

	virtual void BeginPlay() override;

	/** Toggle showing the game menu. */
	UFUNCTION(BlueprintCallable, Category = "UI")
	void ToggleGameMenu();

	/** Show the Game Menu to the viewport. */
	UFUNCTION(BlueprintCallable, Category = "UI")
	void ShowGameMenu();

	/** Hide the Game Menu from the viewport. */
	UFUNCTION(BlueprintCallable, Category = "UI")
	void HideGameMenu();

	/** Toggle showing the player HUD. */
	UFUNCTION(BlueprintCallable, Category = "UI")
	void ToggleGameHUD();

	/** Show the HUD to the viewport. */
	UFUNCTION(BlueprintCallable, Category = "UI")
	void ShowGameHUD();

	/** Hide the HUD from the viewport. */
	UFUNCTION(BlueprintCallable, Category = "UI")
	void HideGameHUD();

	/** Toggle showing the quick access menu. */
	UFUNCTION(BlueprintCallable, Category = "UI")
	void ToggleQuickMenu();

	/** Show the Quick Menu to the viewport. */
	UFUNCTION(BlueprintCallable, Category = "UI")
	void ShowQuickMenu();

	/** Hide the Quick Menu from the viewport. */
	UFUNCTION(BlueprintCallable, Category = "UI")
	void HideQuickMenu();

	UFUNCTION()
	void ScrollUp() { if (DialogueSystem) DialogueSystem->OnScrollUpDialogue.Broadcast(); }

	UFUNCTION()
	void ScrollDown() { if (DialogueSystem) DialogueSystem->OnScrollDownDialogue.Broadcast(); }

	/** Returns the center of the viewport. */
	UFUNCTION(BlueprintCallable, Category = "UI")
	FVector2D GetViewportCenter();

	/** Returns the center of the viewport. */
	UFUNCTION()
	void TurnOffCapsLock() { if (UNIRVWindowsLibrary::IsCapsLockEnabled()) UNIRVWindowsLibrary::SetCapsLockState(false); }
	
};
