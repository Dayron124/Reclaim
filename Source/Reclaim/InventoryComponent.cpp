// Copyright [Your Studio Name] 2025. All Rights Reserved.

#include "InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// We don't need to tick this component every frame, so we turn it off for performance.
	PrimaryComponentTick.bCanEverTick = false;
}

// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UInventoryComponent::AddItem(const FInventoryItem& NewItem)
{
	if (NewItem.ItemID != NAME_None && NewItem.Quantity > 0)
	{
		Items.Add(NewItem);

		if (GEngine)
		{
			FString DebugMessage = FString::Printf(TEXT("Added %d x %s"), NewItem.Quantity, *NewItem.DisplayName);
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, DebugMessage);
		}
	}
}