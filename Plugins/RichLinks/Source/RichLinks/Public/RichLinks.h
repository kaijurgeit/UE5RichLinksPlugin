// Copyright (c) 2025 Kai Jurgeit – MIT License

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FRichLinksModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
