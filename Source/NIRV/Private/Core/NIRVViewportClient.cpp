// Copyright 2020 NIRV Team LLC. All Rights Reserved.
//
#include "Core/NIRVViewportClient.h"

#include "Core/NIRVGameInstance.h"


void UNIRVViewportClient::LostFocus(FViewport* InViewport)
{
	UGameViewportClient::LostFocus(InViewport);
	static_cast<UNIRVGameInstance*>(GameInstance)->OnLostFocus.Broadcast();
}

void UNIRVViewportClient::ReceivedFocus(FViewport* InViewport)
{
	UGameViewportClient::ReceivedFocus(InViewport);
	static_cast<UNIRVGameInstance*>(GameInstance)->OnReceivedFocus.Broadcast();
}
