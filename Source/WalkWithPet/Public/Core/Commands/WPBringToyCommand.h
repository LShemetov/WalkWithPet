// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/Commands/WPCommand.h"
#include "WPBringToyCommand.generated.h"

UCLASS()
class WALKWITHPET_API UWPBringToyCommand : public UWPCommand
{
	GENERATED_BODY()

public:
	virtual void Run() override;
	virtual void Succeeded() override;
	virtual void Failed() override;

private:
	UFUNCTION()
	void BringToy();
};
