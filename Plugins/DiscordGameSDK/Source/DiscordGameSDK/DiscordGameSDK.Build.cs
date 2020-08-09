// Copyright 2020 NIRV Team LLC. All Rights Reserved.
//
using System;
using System.IO;
using UnrealBuildTool;


public class DiscordGameSDK : ModuleRules
{
	public DiscordGameSDK(ReadOnlyTargetRules InTarget) : base(InTarget)
	{
		Console.WriteLine("Using DiscordGameSDK.Build.cs");

        bLegacyPublicIncludePaths = false;
        ShadowVariableWarningLevel = WarningLevel.Error;
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDefinitions.Add("DISCORD_DYNAMIC_LIB=1");

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "DiscordGameSDKLibrary"
        });

        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "CoreUObject",
            "Engine",
            "Slate",
            "SlateCore",
            "Projects",
        });

        if (InTarget.Type == TargetRules.TargetType.Editor) PublicDependencyModuleNames.Add("UnrealEd");

        PublicDefinitions.Add("DISCORD_DYNAMIC_LIB=1");
    }

}
