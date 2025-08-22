// Copyright (c) 2025 Kai Jurgeit – MIT License

using UnrealBuildTool;
using System.Collections.Generic;

public class RichLinksDevEditorTarget : TargetRules
{
	public RichLinksDevEditorTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V4;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_3;
		ExtraModuleNames.Add("RichLinksDev");
	}
}
