// Copyright 2020 NIRV Team LLC. All Rights Reserved.
//
#pragma once
#include <CoreMinimal.h>
#include <Widgets/Images/SImage.h>
#include "Interface/LoadingScreenSettings.h"


class FDeferredCleanupSlateBrush;

/**
 * NIRV Loading Screen.
 */
class SNIRVLoadingScreen : public SCompoundWidget
{
public:
	TSharedRef<SOverlay> Root = SNew(SOverlay);
	TSharedRef<SImage> LoadingScreenImage = SNew(SImage);

private:
	TSharedPtr<FDeferredCleanupSlateBrush> DeferredLoadingScreenImageBrush;

public:
	SLATE_BEGIN_ARGS(SNIRVLoadingScreen) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArguments, const FLoadingScreenDescription& InScreenDescription);

private:
	float GetDPIScale() const;
	static float PointSizeToSlateUnits(float InPointSize);

};
