// Copyright (c) 2025 Kai Jurgeit – MIT License

using UnrealBuildTool;
using System.Collections.Generic;

public class RichLinksDevTarget : TargetRules
{
	public RichLinksDevTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V4;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_3;
		ExtraModuleNames.Add("RichLinksDev");
	}
}
