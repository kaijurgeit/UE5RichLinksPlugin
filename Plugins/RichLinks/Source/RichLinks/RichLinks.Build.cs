// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class RichLinks : ModuleRules
{
	public RichLinks(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
				
		
		PrivateIncludePaths.AddRange(new string[] { });
			
		
		PublicDependencyModuleNames.AddRange(new string[] { "Core", });
			
		
		PrivateDependencyModuleNames.AddRange(new string[] { "CoreUObject", "Engine", "UMG", "Slate", "SlateCore", });
	}
}
