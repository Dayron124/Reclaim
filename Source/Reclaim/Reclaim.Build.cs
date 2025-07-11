// Copyright Epic Games, Inc. All Rights Reserved.
// Updated for Reclaim GDD v1.1

using UnrealBuildTool;

public class Reclaim : ModuleRules
{
    public Reclaim(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        // Core engine modules that are publicly exposed
        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine"
        });

        // Project-specific gameplay modules
        PrivateDependencyModuleNames.AddRange(new string[] {
            "InputCore",
            "EnhancedInput",        // For modern player input
			"PhysicsCore",
            "Niagara",              // For advanced particle effects

			"GameplayAbilities",    // For abilities, attributes, and status effects
			"GameplayTags",
            "GameplayTasks",

            "UMG",                  // For UI elements

			"AIModule",             // For AI logic
			"NavigationSystem",     // For AI pathfinding

			"OnlineSubsystem",      // For base multiplayer functionality
			"OnlineSubsystemEOS"    // For Epic Online Services (optional, for crossplay)
		});

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // To include a specific online subsystem like Steam, add it to the plugins section
        // in your .uproject file with the Enabled attribute set to true
    }
}