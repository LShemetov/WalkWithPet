// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "WPPlayerController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMouseClicked);

class AWPPetToy;

UCLASS()
class WALKWITHPET_API AWPPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AWPPetToy* GetTarget();

public:
	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnMouseClicked OnMouseClicked;
	
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<AWPPetToy> Target;
	
};
