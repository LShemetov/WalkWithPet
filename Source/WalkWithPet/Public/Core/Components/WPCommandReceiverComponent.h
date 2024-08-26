// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WPCommandReceiverComponent.generated.h"

struct FCommandContext;
class UWPCommand;
class AWPPlayerPawn;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WALKWITHPET_API UWPCommandReceiverComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UWPCommandReceiverComponent();
	void ExecuteCommand(TSubclassOf<UWPCommand> CommandClass, FCommandContext CommandContext);
	
	FORCEINLINE UWPCommand* GetExecutableCommand(){ return ExecutableCommand; }

protected:
	void NextCommand();

protected:
	UPROPERTY()
	UWPCommand* ExecutableCommand;

	UPROPERTY()
	UWPCommand* RunningCommand;
	
};
