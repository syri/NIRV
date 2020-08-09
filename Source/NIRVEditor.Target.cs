// Copyright 2020 NIRV Team LLC. All Rights Reserved.
//
using UnrealBuildTool;
using System.Collections.Generic;


public class NIRVEditorTarget : TargetRules
{
	public NIRVEditorTarget(TargetInfo InTarget) : base(InTarget)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("NIRV");
	}

}
