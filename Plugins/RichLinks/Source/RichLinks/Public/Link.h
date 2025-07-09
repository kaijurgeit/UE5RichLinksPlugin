#pragma once
#include "LinkEventReceiver.h"
#include "Blueprint/UserWidget.h"
#include "Components/RichTextBlock.h"
#include "Fonts/FontMeasure.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Layout/SBorder.h"
#include "Framework/Application/SlateApplication.h"

class ULinkRichTextWidget;

class SLink : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SLink) {}
	SLATE_ATTRIBUTE(FText, Text)
	SLATE_ARGUMENT(TWeakObjectPtr<URichTextBlock>, OwnerRichTextBlock)
	SLATE_ARGUMENT(TWeakObjectPtr<UUserWidget>, OwnerWidget)
	SLATE_ARGUMENT(FName, CardId)
SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, const FText& InText, const FString& TagName, const FTextBlockStyle& TextStyle)
	{
		if (InText.IsEmptyOrWhitespace())
		{
			return;
		}
		
		Text = InArgs._Text;
		OwnerRichTextBlock = InArgs._OwnerRichTextBlock;
		OwnerWidget = InArgs._OwnerWidget;
		CardId = InArgs._CardId;
		
		this->SetVisibility(EVisibility::Visible);
		const float LineHeight = FSlateApplication::Get().GetRenderer()->GetFontMeasureService()->GetMaxCharacterHeight(TextStyle.Font, 1.0f);
		
		this->SetVisibility(EVisibility::SelfHitTestInvisible);

		FTextBlockStyle* StylePtr = nullptr;

		if (URichTextBlock* OwnerPtr = OwnerRichTextBlock.Get())
		{
			if (UDataTable* StyleTable = OwnerPtr->GetTextStyleSet())
			{
				static const FName RowName(TEXT("link"));
				FRichTextStyleRow* StyleRow = StyleTable->FindRow<FRichTextStyleRow>(RowName, TEXT("Looking for link style"));

				if (StyleRow)
				{
					StylePtr = &StyleRow->TextStyle;
				}
			}
		}

		FTextBlockStyle Style = StylePtr ? *StylePtr : FTextBlockStyle();
		
		ChildSlot
		[
			SNew(SBox)
			[
				SNew(STextBlock)
				.Text(InText)
				.TextStyle(&Style)
			]
		];
		
		if (OwnerWidget.IsValid() && OwnerWidget->GetClass()->ImplementsInterface(ULinkEventReceiver::StaticClass()))
		{
			ILinkEventReceiver::Execute_AddLinkId(OwnerWidget.Get(), CardId);
		}
	}

	virtual void OnMouseEnter(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override
	{
		if (OwnerWidget.IsValid() && OwnerWidget->GetClass()->ImplementsInterface(ULinkEventReceiver::StaticClass()))
		{
			ILinkEventReceiver::Execute_NotifyOnLinkMouseEnter(OwnerWidget.Get(), CardId);
		}
		SCompoundWidget::OnMouseEnter(MyGeometry, MouseEvent);
	}

	virtual void OnMouseLeave(const FPointerEvent& MouseEvent) override
	{
		if (OwnerWidget.IsValid() && OwnerWidget->GetClass()->ImplementsInterface(ULinkEventReceiver::StaticClass()))
		{
			ILinkEventReceiver::Execute_NotifyOnLinkMouseLeave(OwnerWidget.Get(), CardId);
		}
		SCompoundWidget::OnMouseLeave(MouseEvent);
	}

private:
	TAttribute<FText> Text;
	TWeakObjectPtr<URichTextBlock> OwnerRichTextBlock;
	TWeakObjectPtr<UUserWidget> OwnerWidget;
	FName CardId;
};
