// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Data/WPCoreTypes.h"
#include "WPPetToy.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnToyCollected, EToyType)

UCLASS()
class WALKWITHPET_API AWPPetToy : public AActor
{
	GENERATED_BODY()
	
public:	
	AWPPetToy();
	void Collect();

	FORCEINLINE EToyType& GetToyType() { return ToyType; }

protected:
	virtual void BeginPlay() override;

public:
	FOnToyCollected OnToyCollected;
	
protected:
	UPROPERTY(BlueprintReadOnly, EditInstanceOnly)
	EToyType ToyType;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<USoundBase> CollectSound;
};
