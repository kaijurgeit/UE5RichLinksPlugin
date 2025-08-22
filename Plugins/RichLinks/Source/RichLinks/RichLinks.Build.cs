// Copyright (c) 2025 Kai Jurgeit – MIT License

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
