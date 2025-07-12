// Copyright [Your Studio Name] 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "VitalsComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class RECLAIM_API UVitalsComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UVitalsComponent();

	UFUNCTION(BlueprintCallable, Category = "Vitals")
	void TakeDamage(float DamageAmount);

protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Vitals")
	float Health;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Vitals")
	float MaxHealth;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Vitals")
	float Hunger;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Vitals")
	float MaxHunger;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Vitals")
	float Thirst;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Vitals")
	float MaxThirst;
};