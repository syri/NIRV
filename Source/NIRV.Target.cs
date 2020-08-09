// Copyright 2020 NIRV Team LLC. All Rights Reserved.
//
using UnrealBuildTool;
using System.Collections.Generic;


public class NIRVTarget : TargetRules
{
	public NIRVTarget(TargetInfo InTarget) : base(InTarget)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("NIRV");
	}

}
