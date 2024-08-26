// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "WPPlayerPawn.generated.h"

class AWPPetToy;
class AWPPlayerController;
class UWPMainWidget;
class AWPPetPawn;
class UWPCommand;

UCLASS()
class WALKWITHPET_API AWPPlayerPawn : public APawn
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	void AcceptCommandRequest(TSubclassOf<UWPCommand> CommandClass);
	
	UFUNCTION()
	void ChangeTarget();

protected:
	UPROPERTY()
	TObjectPtr<AWPPetPawn> PetPawn;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UWPMainWidget> MainWidgetClass;

	UPROPERTY()
	TObjectPtr<UWPMainWidget> MainWidget;

	UPROPERTY()
	TObjectPtr<AWPPlayerController> PlayerController;
};
