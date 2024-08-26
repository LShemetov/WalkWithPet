// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/Commands/WPCommand.h"
#include "WPSitDownCommand.generated.h"

UCLASS()
class WALKWITHPET_API UWPSitDownCommand : public UWPCommand
{
	GENERATED_BODY()

public:
	virtual void Run() override;

protected:
	virtual void Failed() override;

	UFUNCTION()
	void OnAnimFinishedHandle();
};
