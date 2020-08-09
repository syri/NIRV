// Copyright 2020 NIRV Team LLC. All Rights Reserved.
//
#pragma once
#include <CoreMinimal.h>

#include "NIRVDialogueSystem.generated.h"


UENUM()
enum class EDialogueType
{
	Classic = 1,
	ClassicCharacter,
	Freeplay,
	Alert,
	Abovehead

};

USTRUCT(BlueprintType)
struct FDialogueData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EDialogueType DialogueType;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	uint8 QueuePosition;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText DialogueTableName;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString DialogueTableKey;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName CharacterName;

};

UDELEGATE(BlueprintCallable)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FClassicDialogueDelegate, FDialogueData, DialogueData);

UDELEGATE(BlueprintCallable)
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FScrollUpEvent);

UDELEGATE(BlueprintCallable)
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FScrollDownEvent);


/**
 * Event forwarder and text parser for dialogue events.
 */
UCLASS(BlueprintType)
class NIRV_API UNIRVDialogueSystem : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintAssignable, Category = "NIRV|Events")
	FClassicDialogueDelegate OnCreateClassicDialogue;

	UPROPERTY(BlueprintAssignable, Category = "NIRV|Events")
	FScrollUpEvent OnScrollUpDialogue;

	UPROPERTY(BlueprintAssignable, Category = "NIRV|Events")
	FScrollDownEvent OnScrollDownDialogue;

public:
	UNIRVDialogueSystem();

	UFUNCTION(BlueprintCallable, Category = "NIRV|Dialogue")
	void CreateDialogue(FDialogueData InDialogueData);
	
};
