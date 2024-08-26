// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/WPMainWidget.h"
#include "Components/ListView.h"
#include "Core/WPGameStateBase.h"
#include "Core/Pet/Toys/WPPetToy.h"
#include "Data/WPButtonInfo.h"
#include "Data/WPListObjectData.h"
#include "Kismet/GameplayStatics.h"
#include "UI/WPCommandButton.h"

void UWPMainWidget::SetTarget(AWPPetToy* InTarget)
{
	if (InTarget)
	{
		const auto StringTargetName = UEnum::GetValueAsString(InTarget->GetToyType());
		TargetName->SetText(FText::FromString(StringTargetName));
		InTarget->OnToyCollected.AddUObject(this, &ThisClass::ClearTarget);
	} else
	{
		ClearTarget(EToyType::None);
	}
}

void UWPMainWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if(!ButtonInfoData)
	{
		return;
	}

	auto& ButtonsInfo = ButtonInfoData->ButtonsInfo;
	ObjectsData.Reserve(ButtonsInfo.Num());
	ObjectsData.Empty();
	for (const auto& ButtonInfo : ButtonsInfo)
	{
		if (UWPListObjectData* CurrentObjectData = NewObject<UWPListObjectData>())
		{
			CurrentObjectData->SetObjectData(ButtonInfo);
			ObjectsData.Add(CurrentObjectData);
			CurrentObjectData->OnClicked.BindUObject(this, &ThisClass::OnCommandButtonClickedHandle);
		}
	}
	CommandButtonsBox->SetListItems(ObjectsData);

	const auto GameState = Cast<AWPGameStateBase>(UGameplayStatics::GetGameState(this));
	if (!GameState) return;
	GameState->OnToysCollectionUpdated.BindUObject(this, &ThisClass::OnToysCollectionUpdatedHandle);

	ClearTarget(EToyType::None);
}

void UWPMainWidget::OnCommandButtonClickedHandle(UWPListObjectData* InObjectData) const
{
	if (InObjectData)
	{
		OnCommandButtonClicked.ExecuteIfBound(InObjectData->GetObjectData().CommandClass);
	}
}

void UWPMainWidget::ClearTarget(EToyType InToyType)
{
	if (!TargetName) return;
	TargetName->SetText(FText::FromString("NO TARGET"));
}
