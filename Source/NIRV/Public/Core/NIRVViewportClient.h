// Copyright 2020 NIRV Team LLC. All Rights Reserved.
//
#pragma once
#include <CoreMinimal.h>
#include "NIRVViewportClient.generated.h"


/**
 * NIRV Viewport Client.
 */
UCLASS()
class NIRV_API UNIRVViewportClient : public UGameViewportClient
{
	GENERATED_BODY()

public:
	/** Run when the current game window loses focus. */
	virtual void LostFocus(FViewport* InViewport) override;
	/** Run when the current game window receives focus. */
	virtual void ReceivedFocus(FViewport* InViewport) override;

};
