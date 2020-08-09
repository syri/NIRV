// Copyright 2020 NIRV Team LLC. All Rights Reserved.
//
#pragma once
#include <CoreMinimal.h>
#include "Interface/LoadingScreenSettings.h"

#include "NIRVGameInstance.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FLostFocusSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FReceivedFocusSignature);


/**
 * NIRV Game Instance.
 */
UCLASS()
class NIRV_API UNIRVGameInstance : public UGameInstance
{
	GENERATED_BODY()

	friend class FDefaultGameMoviePlayer;

public:
	UPROPERTY(BlueprintAssignable, Category = "NIRV|Events")
	FLostFocusSignature OnLostFocus;
	UPROPERTY(BlueprintAssignable, Category = "NIRV|Events")
	FReceivedFocusSignature OnReceivedFocus;

public:
	virtual void Init() override;
	virtual void Shutdown() override;
	
private:
	void HandlePrepareLoadingScreen();

	void BeginLoadingScreen(const FLoadingScreenDescription& InScreenDescription);

};
