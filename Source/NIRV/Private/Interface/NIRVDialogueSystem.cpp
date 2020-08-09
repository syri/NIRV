// Copyright 2020 NIRV Team LLC. All Rights Reserved.
//
#include "Interface/NIRVDialogueSystem.h"


UNIRVDialogueSystem::UNIRVDialogueSystem()
{}

void UNIRVDialogueSystem::CreateDialogue(FDialogueData InDialogueData)
{
	switch (InDialogueData.DialogueType)
	{
	case EDialogueType::Classic:
		OnCreateClassicDialogue.Broadcast(InDialogueData);
		break;

	default:
		OnCreateClassicDialogue.Broadcast(InDialogueData);
		break;
	}
}
