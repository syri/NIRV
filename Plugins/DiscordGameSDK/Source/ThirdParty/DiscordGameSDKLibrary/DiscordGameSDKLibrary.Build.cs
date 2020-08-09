// Copyright 2020 NIRV Team LLC. All Rights Reserved.
//
using System;
using System.IO;
using UnrealBuildTool;
using Tools.DotNETCommon;


public class DiscordGameSDKLibrary : ModuleRules
{
	public DiscordGameSDKLibrary(ReadOnlyTargetRules InTarget) : base(InTarget)
    {
		string BaseDirectory = Path.GetFullPath(Path.Combine(ModuleDirectory, "..", "..", "ThirdParty", "DiscordGameSDKLibrary"));
		Console.WriteLine("Using DiscordGameSDKLibrary.Build.cs");

        Type = ModuleType.External;
		bLegacyPublicIncludePaths = false;
		ShadowVariableWarningLevel = WarningLevel.Error;

		PublicDefinitions.Add("DISCORD_DYNAMIC_LIB=1");

		if (InTarget.Platform == UnrealTargetPlatform.Win64)
		{
			string Library = Path.Combine(BaseDirectory, "Win64");

			PublicIncludePaths.Add(Path.Combine(BaseDirectory, "Include"));

			LinkStaticLibrary(Path.Combine(Library, "discord_game_sdk.dll.lib"));
			AddDllDependency(Path.Combine(Library, "discord_game_sdk.dll"));

			PublicDelayLoadDLLs.Add("discord_game_sdk.dll");
		}
	}

	private void LinkStaticLibrary(string InFullLibraryPath)
	{
		if (!File.Exists(InFullLibraryPath))
			Fail("Unable to locate any build library: " + InFullLibraryPath);

		// Found a library; add it to the dependencies list.
		PublicAdditionalLibraries.Add(InFullLibraryPath);
		Trace("Added static library: {0}", InFullLibraryPath);
	}


	private void AddDllDependency(string InFullDLLPath)
	{
		if (!File.Exists(InFullDLLPath))
			Fail("Unable to locate any build library: " + InFullDLLPath);

		// Found a library; add it to the dependencies list.
		RuntimeDependencies.Add(InFullDLLPath);
		Trace("Added runtime dll library: {0}", InFullDLLPath);
	}

	/**
	 * Print out a build message.
	 */
	private void Trace(string InMessage)
	{
		Log.TraceInformation("DiscordGameSDKLibrary: " + InMessage);
	}

	/** Trace helper. */
	private void Trace(string InFormat, params object[] InArguments)
	{
		Trace(string.Format(InFormat, InArguments));
	}

	private void Fail(string InMessage)
	{
		Trace(InMessage);
		throw new Exception(InMessage);
	}

}
