// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/Player/WPPlayerPawn.h"
#include "Data/WPCoreTypes.h"
#include "WPCommand.generated.h"

UCLASS()
class WALKWITHPET_API UWPCommand : public UObject
{
	GENERATED_BODY()

public:
	virtual void Run() { }
	virtual void Stop();

	FORCEINLINE void SetCommandContext(const FCommandContext& InCommandContext) { CommandContext = InCommandContext; }
	FORCEINLINE bool GetStatus() const { return bIsCompleted; }

protected:
	UFUNCTION()
	virtual void Succeeded();

	UFUNCTION()
	virtual void Failed();

public:
	FSimpleDelegate OnStopped;

protected:
	FCommandContext CommandContext;
	bool bIsCompleted;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	USoundBase* StartSound;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	USoundBase* EndSound;
	
};
