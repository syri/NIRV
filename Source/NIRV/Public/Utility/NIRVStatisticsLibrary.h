// Copyright 2020 NIRV Team LLC. All Rights Reserved.
//
#pragma once
#include <CoreMinimal.h>
//#include <DynamicRHI.h>
#include <RHI.h>

#include "NIRVStatisticsLibrary.generated.h"


/** How many cycles the Game Thread used (excluding idle time). */
extern RENDERCORE_API uint32 GGameThreadTime;
/** How many cycles the Render Thread used (excluding idle time). */
extern RENDERCORE_API uint32 GRenderThreadTime;

/**
 * NIRV Statics Function Library.
 */
UCLASS()
class NIRV_API UNIRVStatisticsLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	/** Get the game's current time in seconds. */
	UFUNCTION(BlueprintPure, Category = "NIRV|Statistics")
	static const float GetCurrentTime() { return FApp::GetCurrentTime(); }

	/** Get the game's delta time in seconds. */
	UFUNCTION(BlueprintPure, Category = "NIRV|Statistics")
	static const float GetNIRVDeltaTime() { return FApp::GetDeltaTime(); }

	/** Get the CPU frame time in milliseconds. */
	UFUNCTION(BlueprintPure, DisplayName = "Get CPU Frame Time", Category = "NIRV|Statistics")
	static const float GetCPUFrameTime() { return FPlatformTime::ToMilliseconds(GGameThreadTime); }

	/** Get the GPU frame time in milliseconds. */
	UFUNCTION(BlueprintPure, DisplayName = "Get GPU Frame Time", Category = "NIRV|Statistics")
	static const float GetGPUFrameTime() { return FPlatformTime::ToMilliseconds(RHIGetGPUFrameCycles()); }

	/** Get the total frame time in milliseconds. */
	UFUNCTION(BlueprintPure, Category = "NIRV|Statistics")
	static const float GetTotalFrameTime() { return FApp::GetDeltaTime() * 1000.f; }

	/** Get the current frames per second (FPS). */
	UFUNCTION(BlueprintPure, Category = "NIRV|Statistics")
	static const float GetFPS() { return 1000 / (FApp::GetDeltaTime() * 1000.f); }

	/** Get the current VRAM usage in gigabytes (Gigabyte). */
	UFUNCTION(BlueprintPure, DisplayName = "Get VRAM Usage", Category = "NIRV|Statistics")
	static const float GetVRAMUsage()
	{
		FTextureMemoryStats TemporaryStats;
		RHIGetTextureMemoryStats(TemporaryStats);

		return (float)TemporaryStats.AllocatedMemorySize / 1000000000;
	}

};
