// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Data/WPCoreTypes.h"
#include "WPMainWidget.generated.h"

class UTextBlock;
class UVerticalBox;
class UWPListObjectData;
class UListView;
class UWPButtonInfo;
class UWPCommand;
struct FButtonInfo;

DECLARE_DELEGATE_OneParam(FOnCommandButtonClicked, TSubclassOf<UWPCommand> CommandClass)

UCLASS(Abstract)
class WALKWITHPET_API UWPMainWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetTarget(AWPPetToy* InTarget);
	
protected:
	virtual void NativeConstruct() override;

	void OnCommandButtonClickedHandle(UWPListObjectData* InObjectData) const;
	void ClearTarget(EToyType InToyType);
	
	UFUNCTION(BlueprintImplementableEvent)
	void OnToysCollectionUpdatedHandle(FToysCollection InToysCollection);

public:
	FOnCommandButtonClicked OnCommandButtonClicked;
	
protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UListView> CommandButtonsBox;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UWPButtonInfo> ButtonInfoData;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UVerticalBox> ToysCollectionContainer;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UTextBlock> TargetName;

	UPROPERTY()
	TArray<UWPListObjectData*> ObjectsData;
	
};
