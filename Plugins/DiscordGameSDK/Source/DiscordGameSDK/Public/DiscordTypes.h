// Copyright 2020 NIRV Team LLC. All Rights Reserved.
//
#pragma once
#include <CoreMinimal.h>


UENUM()
enum class ECreateFlags : uint64
{
	Default = 0,
	NoRequireDiscord = 1,
};

static ECreateFlags FStringToCreateFlags(FString InString)
{
	if (InString == "NoRequireDiscord") return ECreateFlags::NoRequireDiscord;
	else return ECreateFlags::Default;
}
