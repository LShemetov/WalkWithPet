// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/Commands/WPCommand.h"
#include "WPComeToMeCommand.generated.h"

UCLASS()
class WALKWITHPET_API UWPComeToMeCommand : public UWPCommand
{
	GENERATED_BODY()

public:
	virtual void Run() override;
	virtual void Failed() override;
};
