// Copyright 2020 NIRV Team LLC. All Rights Reserved.
//
#include "Interface/SLoadingScreen.h"

#include <Widgets/Images/SThrobber.h>
#include <Widgets/Layout/SSpacer.h>
#include <Widgets/Layout/SSafeZone.h>
#include <Widgets/Layout/SDPIScaler.h>
#include <Engine/UserInterfaceSettings.h>
#include <Slate/DeferredCleanupSlateBrush.h>


void SNIRVLoadingScreen::Construct(const FArguments& InArgs, const FLoadingScreenDescription& InScreenDescription)
{
	const ULoadingScreenSettings* Settings = GetDefault<ULoadingScreenSettings>();

	// Get background image.
	const FStringAssetReference& LoadingScreenImageAsset = InScreenDescription.LoadingImage;
	UObject* LoadingScreenImageObject = LoadingScreenImageAsset.TryLoad();
	FSlateBrush LoadingScreenImageBrush = FSlateBrush();
	LoadingScreenImageBrush.SetResourceObject(LoadingScreenImageObject);

	if (LoadingScreenImageObject)
	{
		DeferredLoadingScreenImageBrush = FDeferredCleanupSlateBrush::CreateBrush(LoadingScreenImageBrush);
		LoadingScreenImage->SetImage(DeferredLoadingScreenImageBrush.IsValid() ? DeferredLoadingScreenImageBrush->GetSlateBrush() : nullptr);

		Root->AddSlot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SScaleBox)
				.Stretch(InScreenDescription.ImageStretch)
			[
				LoadingScreenImage
			]];
	}

	TSharedRef<SWidget> RedistributionWarningWidget = SNullWidget::NullWidget;
#if !UE_BUILD_SHIPPING
	RedistributionWarningWidget = SNew(STextBlock)
		.Font(Settings->RedistributionWarningFont)
		.Text(FText::FromString(TEXT("Development Build. Do Not Redistribute.")));
#else
	RedistributionWarningWidget = SNew(SSpacer);
#endif

	Root->AddSlot()
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Bottom)
		[
			RedistributionWarningWidget
		];

	ChildSlot
		[
			Root
		];
}

float SNIRVLoadingScreen::GetDPIScale() const
{
	const FVector2D& DrawSize = GetCachedGeometry().ToPaintGeometry().GetLocalSize();
	const FIntPoint Size((int32)DrawSize.X, (int32)DrawSize.Y);
	return GetDefault<UUserInterfaceSettings>()->GetDPIScaleBasedOnSize(Size);
}

float SNIRVLoadingScreen::PointSizeToSlateUnits(float InPointSize)
{
	//FreeTypeConstants::HorizontalDPI = 96;
	const float SlateFreeTypeHorizontalResolutionDPI = 96.0f;
	const float FreeTypeNativeDPI = 72.0f;
	const float PixelSize = InPointSize * (SlateFreeTypeHorizontalResolutionDPI / FreeTypeNativeDPI);

	return PixelSize;
}
