// Copyright 2020 NIRV Team LLC. All Rights Reserved.
//
#include "Core/NIRVGameMode.h"

#include <Blueprint/UserWidget.h>


ANIRVGameMode::ANIRVGameMode()
{}

void ANIRVGameMode::BeginPlay()
{}

void ANIRVGameMode::EndPlay(const EEndPlayReason::Type InEndPlayReason)
{}

void ANIRVGameMode::StartSlowMotion(const float InValue)
{
	if (!bIsTimeSlowed)
	{
		GetWorldSettings()->SetTimeDilation(InValue);
		bIsTimeSlowed = true;
	}
}

void ANIRVGameMode::StopSlowMotion()
{
	if (bIsTimeSlowed)
	{
		GetWorldSettings()->SetTimeDilation(1.f);
		bIsTimeSlowed = false;
	}
}
