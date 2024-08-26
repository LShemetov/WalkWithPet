// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "WPPetPawn.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnActionCallback);

class UWPCommandReceiverComponent;

UCLASS()
class WALKWITHPET_API AWPPetPawn : public APawn
{
	GENERATED_BODY()

public:
	AWPPetPawn();
	FORCEINLINE UWPCommandReceiverComponent* GetCommandReceiverComponent(){ return CommandReceiverComponent; }
	FORCEINLINE bool GetCrouchState() const { return bIsCrouch; }

	UFUNCTION(BlueprintImplementableEvent)
	void WalkToTarget(AActor* Target);

	UFUNCTION(BlueprintImplementableEvent)
	void WalkInLocation(FVector InLocation);

	UFUNCTION(BlueprintImplementableEvent)
	void StopWalk();

	UFUNCTION(BlueprintImplementableEvent)
	void SetCrouchState(bool bInCrouch);

public:
	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnActionCallback OnActionSucceeded;
	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnActionCallback OnActionFailed;
	
protected:
	UPROPERTY()
	TObjectPtr<UWPCommandReceiverComponent> CommandReceiverComponent;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bIsCrouch;

};
