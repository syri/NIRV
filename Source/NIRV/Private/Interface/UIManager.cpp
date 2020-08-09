// Copyright 2020 NIRV Team LLC. All Rights Reserved.
//
#include "Interface/UIManager.h"

#include <Blueprint/UserWidget.h>
#include <Kismet/GameplayStatics.h>


AUIManager::AUIManager()
{
	QuickMenuTimeDilation = 0.075f;
}

void AUIManager::BeginPlay()
{
	GameMode = Cast<ANIRVGameMode>(GetWorld()->GetAuthGameMode());

	DialogueSystem = NewObject<UNIRVDialogueSystem>();
}

void AUIManager::ToggleGameMenu()
{
	if (GameMenuReference)
	{
		if (GameMenu && GameMenu->IsVisible()) HideGameMenu();
		else ShowGameMenu();
	}
}

void AUIManager::ShowGameMenu()
{
	if (QuickMenuReference && QuickMenu && QuickMenu->IsVisible()) HideQuickMenu();

	GameMode->StartSlowMotion(QuickMenuTimeDilation);

	if (GameMenuReference && (!GameMenu || !GameMenu->IsInViewport()))
	{
		GameMenu = CreateWidget<UUserWidget>(GetWorld()->GetFirstPlayerController(), GameMenuReference);
		if (GameMenu) GameMenu->AddToViewport();
	}

	if (GameMenuReference && GameMenu) GameMenu->SetVisibility(ESlateVisibility::Visible);

	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeGameAndUI().SetHideCursorDuringCapture(false));
	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
	GetWorld()->GetFirstPlayerController()->SetMouseLocation(GetViewportCenter().X, GetViewportCenter().Y);

	HideGameHUD();
}

void AUIManager::HideGameMenu()
{
	GameMode->StopSlowMotion();

	if (GameMenuReference && GameMenu)
	{
		GameMenu->SetVisibility(ESlateVisibility::Hidden);
		if (GameMenu->IsInViewport()) GameMenu->RemoveFromParent();
	}

	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeGameOnly());
	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = false;

	ShowGameHUD();
}

void AUIManager::ToggleGameHUD()
{
	if (HUDReference)
	{
		if (HUD && HUD->IsVisible()) HideGameHUD();
		else ShowGameHUD();
	}
}

void AUIManager::ShowGameHUD()
{
	if (HUDReference && (!HUD || !HUD->IsInViewport()))
	{
		HUD = CreateWidget<UUserWidget>(GetWorld()->GetFirstPlayerController(), HUDReference);
		if (HUD) HUD->AddToViewport();
	}

	if (HUDReference && HUD) HUD->SetVisibility(ESlateVisibility::Visible);
}

void AUIManager::HideGameHUD()
{
	if (HUDReference && HUD)
	{
		HUD->SetVisibility(ESlateVisibility::Hidden);
		if (HUD->IsInViewport()) HUD->RemoveFromParent();
	}
}

void AUIManager::ToggleQuickMenu()
{
	if (QuickMenuReference)
	{
		if (QuickMenu && QuickMenu->IsVisible()) HideQuickMenu();
		else ShowQuickMenu();
	}
}

void AUIManager::ShowQuickMenu()
{
	if (GameMenuReference && GameMenu && GameMenu->IsVisible()) return;

	GameMode->StartSlowMotion(QuickMenuTimeDilation);

	if (QuickMenuReference && (!QuickMenu || !QuickMenu->IsInViewport()))
	{
		QuickMenu = CreateWidget<UUserWidget>(GetWorld()->GetFirstPlayerController(), QuickMenuReference);
		if (QuickMenu) QuickMenu->AddToViewport();
	}

	if (QuickMenuReference && QuickMenu) QuickMenu->SetVisibility(ESlateVisibility::Visible);

	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeGameAndUI().SetHideCursorDuringCapture(false));
	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
	GetWorld()->GetFirstPlayerController()->SetMouseLocation(GetViewportCenter().X, GetViewportCenter().Y);

	GetWorldTimerManager().ClearTimer(CapsLockResetTimer);

	HideGameHUD();
}

void AUIManager::HideQuickMenu()
{
	if (GameMenuReference && GameMenu && GameMenu->IsVisible()) return;

	GameMode->StopSlowMotion();

	if (QuickMenuReference && QuickMenu)
	{
		QuickMenu->SetVisibility(ESlateVisibility::Hidden);
		if (QuickMenu->IsInViewport()) QuickMenu->RemoveFromParent();
	}

	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeGameOnly());
	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = false;

	GetWorldTimerManager().SetTimer(CapsLockResetTimer, this, &AUIManager::TurnOffCapsLock, 1.f, false);

	ShowGameHUD();
}

FVector2D AUIManager::GetViewportCenter()
{
	const FVector2D ViewportSize = FVector2D(GEngine->GameViewport->Viewport->GetSizeXY());
	const FVector2D ViewportCenter = FVector2D(ViewportSize.X / 2, ViewportSize.Y / 2);

	return ViewportCenter;
}
