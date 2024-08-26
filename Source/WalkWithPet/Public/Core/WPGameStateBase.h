// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/WPCoreTypes.h"
#include "GameFramework/GameStateBase.h"
#include "WPGameStateBase.generated.h"

DECLARE_DELEGATE_OneParam(FOnToysCollectionUpdated, FToysCollection)

enum class EToyType : uint8;

UCLASS()
class WALKWITHPET_API AWPGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	void OnToyCollectedHandle(EToyType InToyType);

public:
	 FOnToysCollectionUpdated OnToysCollectionUpdated;
	
protected:
	FToysCollection ToysCollection;
};
