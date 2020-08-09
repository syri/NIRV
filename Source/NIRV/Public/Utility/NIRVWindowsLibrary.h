// Copyright 2020 NIRV Team LLC. All Rights Reserved.
//
#pragma once
#include <CoreMinimal.h>

#include "NIRVWindowsLibrary.generated.h"


/**
 * NIRV Windows Function Library.
 */
UCLASS()
class NIRV_API UNIRVWindowsLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** Change the CapsLock state. Typically used to allow CapsLock to act like a normal key. */
	UFUNCTION(BlueprintCallable, Category = "NIRV|Input")
	static bool SetCapsLockState(const bool bInState);

	/** Get the current state of the CapsLock key. */
	UFUNCTION(BlueprintCallable, Category = "NIRV|Input")
	static bool IsCapsLockEnabled();

};
