// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "LinkEventReceiver.generated.h"

// This class does not need to be modified.
UINTERFACE(Blueprintable)
class RICHLINKS_API ULinkEventReceiver : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */

class RICHLINKS_API ILinkEventReceiver
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "RichLinks")
	void NotifyOnLinkMouseEnter(const FName& LinkId);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "RichLinks")
	void NotifyOnLinkMouseLeave(const FName& LinkId);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "RichLinks")
	void NotifyOnLinkMouseButtonDown(const FName& LinkId);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "RichLinks")
	void AddLinkId(const FName& LinkId);
};
