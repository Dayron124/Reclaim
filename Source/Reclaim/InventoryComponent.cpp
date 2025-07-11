// Copyright [Your Studio Name] 2025. All Rights Reserved.

#include "InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.
	// You can turn these features off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}

// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UInventoryComponent::AddItem(const FInventoryItem& NewItem)
{
	// Ensure the item and quantity are valid before adding.
	if (NewItem.ItemID != NAME_None && NewItem.Quantity > 0)
	{
		// For now, we just add the item. 
		// Later, this logic can be expanded to stack items.
		Items.Add(NewItem);

		// Print a debug message to the screen to verify it's working.
		if (GEngine)
		{
			FString DebugMessage = FString::Printf(TEXT("Added %d x %s"), NewItem.Quantity, *NewItem.DisplayName);
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, DebugMessage);
		}
	}
}