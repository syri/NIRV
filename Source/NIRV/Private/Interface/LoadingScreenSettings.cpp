// Copyright 2020 NIRV Team LLC. All Rights Reserved.
//
#include "Interface/LoadingScreenSettings.h"

#include <Engine/Font.h>


ULoadingScreenSettings::ULoadingScreenSettings()
{
	if (!IsRunningDedicatedServer())
	{
		static ConstructorHelpers::FObjectFinder<UFont> MontserratFontObject(TEXT("/Game/Resources/Fonts/Montserrat/FNT_Montserrat"));

		RedistributionWarningFont = FSlateFontInfo(MontserratFontObject.Object, 16, FName("Semibold"));
	}
}
