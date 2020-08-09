// Copyright 2020 NIRV Team LLC. All Rights Reserved.
//
using System;
using System.IO;
using UnrealBuildTool;


public class NIRV : ModuleRules
{
    public NIRV(ReadOnlyTargetRules InTarget) : base(InTarget)
    {
        Console.WriteLine("Using NIRV.Build.cs");

        bLegacyPublicIncludePaths = false;
        ShadowVariableWarningLevel = WarningLevel.Error;
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "MoviePlayer",
            "Projects",
            "RenderCore",
            "RHI",
            "Slate",
            "SlateCore",
            "UMG"
        });
    }

}
