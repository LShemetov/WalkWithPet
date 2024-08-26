// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/Commands/WPCommand.h"
#include "WPGoForAWalkCommand.generated.h"

UCLASS()
class WALKWITHPET_API UWPGoForAWalkCommand : public UWPCommand
{
	GENERATED_BODY()


public:
	virtual void Run() override;
	virtual void Succeeded() override;
	virtual void Failed() override;

private:
	FVector GenerateLocation();
	void ChooseNewLocation();

private:
	FVector InitLocation = FVector(0.f);
	float Radius = 2000.f;
	float WaitTime = 3.f;
	FTimerHandle WaitTimerHandle;
};
