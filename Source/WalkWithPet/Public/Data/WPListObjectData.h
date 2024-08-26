// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WPButtonInfo.h"
#include "WPListObjectData.generated.h"


struct FButtonInfo;

UCLASS()
class WALKWITHPET_API UWPListObjectData : public UObject
{
	GENERATED_BODY()
	
public:
	FORCEINLINE void SetObjectData(const FButtonInfo& InObjectData) { ObjectData = InObjectData; }
	FORCEINLINE FButtonInfo& GetObjectData() { return ObjectData; }

public:
	DECLARE_DELEGATE_OneParam(FOnCommandButtonClicked, UWPListObjectData*)
	FOnCommandButtonClicked OnClicked;

private:
	FButtonInfo ObjectData;
};
