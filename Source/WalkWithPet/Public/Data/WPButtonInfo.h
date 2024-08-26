// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "WPButtonInfo.generated.h"

class UWPCommand;

USTRUCT(BlueprintType)
struct FButtonInfo
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TSubclassOf<UWPCommand> CommandClass;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	FText CommandName;
};

UCLASS()
class WALKWITHPET_API UWPButtonInfo : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TArray<FButtonInfo> ButtonsInfo;
};
