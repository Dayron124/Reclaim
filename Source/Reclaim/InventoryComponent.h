// Copyright [Your Studio Name] 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

/**
 * Defines the data for a single item in the inventory.
 */
USTRUCT(BlueprintType)
struct FInventoryItem
{
	GENERATED_BODY()

public:
	// Expose ItemID to be set when creating the struct in Blueprints.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FName ItemID;

	// Expose DisplayName to be set when creating the struct in Blueprints.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FString DisplayName;

	// The current quantity of this item stack.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int32 Quantity;

	// Default constructor
	FInventoryItem() : ItemID(NAME_None), Quantity(0) {}
};

/**
 * Manages a collection of items for an actor. Can be added to players, containers, etc.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class RECLAIM_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInventoryComponent();

	/**
	 * Adds a new item to the inventory.
	 * @param NewItem The item to add.
	 */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void AddItem(const FInventoryItem& NewItem);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	// The array of items currently held in this inventory.
	UPROPERTY(VisibleAnywhere, Category = "Inventory")
	TArray<FInventoryItem> Items;

};