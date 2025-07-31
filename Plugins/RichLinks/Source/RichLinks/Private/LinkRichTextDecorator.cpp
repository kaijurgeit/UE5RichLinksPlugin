#include "LinkRichTextDecorator.h"
#include "Link.h"

FLinkRichTextDecorator::FLinkRichTextDecorator(URichTextBlock* InOwner, UUserWidget* InWidgetOwner)
	: FRichTextDecorator(InOwner), OwnerWidget(InWidgetOwner)
{
	SupportedTags = { TEXT("link") };
}

bool FLinkRichTextDecorator::Supports(const FTextRunParseResults& RunParseResult, const FString& Text) const
{
	return SupportedTags.Contains(RunParseResult.Name);
}

TSharedPtr<SWidget> FLinkRichTextDecorator::CreateDecoratorWidget(const FTextRunInfo& RunInfo,
	const FTextBlockStyle& TextStyle) const
{
	const FName LinkId(*RunInfo.MetaData.Find("id"));
	
	return SNew(SLink, RunInfo.Content, RunInfo.Name, TextStyle).OwnerRichTextBlock(Owner).OwnerWidget(OwnerWidget).LinkId(LinkId);
}

