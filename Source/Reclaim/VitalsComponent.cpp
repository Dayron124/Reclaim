// Copyright [Your Studio Name] 2025. All Rights Reserved.

#include "VitalsComponent.h"

UVitalsComponent::UVitalsComponent()
{
	// Enable ticking so we can deplete vitals over time.
	PrimaryComponentTick.bCanEverTick = true;

	// Set default max values.
	MaxHealth = 100.0f;
	MaxHunger = 100.0f;
	MaxThirst = 100.0f;
}

void UVitalsComponent::BeginPlay()
{
	Super::BeginPlay();

	// Initialize current vitals to their max values.
	Health = MaxHealth;
	Hunger = MaxHunger;
	Thirst = MaxThirst;
}

void UVitalsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Deplete hunger and thirst over time (values can be adjusted).
	Hunger = FMath::Clamp(Hunger - (0.1f * DeltaTime), 0.0f, MaxHunger);
	Thirst = FMath::Clamp(Thirst - (0.2f * DeltaTime), 0.0f, MaxThirst);

	// Add the debug message here
	if (GEngine)
	{
		FString VitalsMessage = FString::Printf(TEXT("Health: %.1f | Hunger: %.1f | Thirst: %.1f"), Health, Hunger, Thirst);
		GEngine->AddOnScreenDebugMessage(1, 0.0f, FColor::Yellow, VitalsMessage); // Using key '1' prevents it from spamming the screen
	}
}

void UVitalsComponent::TakeDamage(float DamageAmount)
{
	if (DamageAmount <= 0.0f)
	{
		return;
	}

	Health = FMath::Clamp(Health - DamageAmount, 0.0f, MaxHealth);

	if (GEngine)
	{
		FString DebugMessage = FString::Printf(TEXT("Took %.1f damage. Health is now %.1f"), DamageAmount, Health);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, DebugMessage);
	}

	if (Health <= 0.0f)
	{
		// In the future, handle player death here.
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Black, TEXT("Player has died."));
	}
}