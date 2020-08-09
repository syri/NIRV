// Copyright 2020 NIRV Team LLC. All Rights Reserved.
//
#pragma once
#include <CoreMinimal.h>
#include <Misc/App.h>

#include "NIRVGeneralLibrary.generated.h"


/**
 * Available build configurations.
 */
UENUM(BlueprintType)
enum class ENIRVBuildConfiguration : uint8
{
	/** Unknown build configuration. */
	Unknown,
	/** Debug build. */
	Debug,
	/** DebugGame build. */
	DebugGame,
	/** Development build. */
	Development,
	/** Shipping build. */
	Shipping,
	/** Test build. */
	Test
};

/**
 * NIRV Windows General Library.
 */
UCLASS()
class NIRV_API UNIRVGeneralLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** Returns the current build configuration. */
	UFUNCTION(BlueprintPure, Category = "NIRV|Utility")
	static ENIRVBuildConfiguration GetNIRVBuildConfiguration()
	{
		EBuildConfiguration BuildConfiguration = FApp::GetBuildConfiguration();

		ENIRVBuildConfiguration Result;

		switch (BuildConfiguration)
		{
		case EBuildConfiguration::Debug:
			Result = ENIRVBuildConfiguration::Debug;
			break;

		case EBuildConfiguration::DebugGame:
			Result = ENIRVBuildConfiguration::DebugGame;
			break;

		case EBuildConfiguration::Development:
			Result = ENIRVBuildConfiguration::Development;
			break;

		case EBuildConfiguration::Shipping:
			Result = ENIRVBuildConfiguration::Shipping;
			break;

		case EBuildConfiguration::Test:
			Result = ENIRVBuildConfiguration::Test;
			break;

		default:
			Result = ENIRVBuildConfiguration::Unknown;
			break;
		}

		return Result;
	}

};
