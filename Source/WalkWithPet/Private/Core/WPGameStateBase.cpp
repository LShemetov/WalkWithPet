// Fill out your copyright notice in the Description page of Project Settings.

#include "Core/WPGameStateBase.h"
#include "Core/Pet/Toys/WPPetToy.h"
#include "Kismet/GameplayStatics.h"

void AWPGameStateBase::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> Toys;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWPPetToy::StaticClass(), Toys);

	if (Toys.Num() == 0) return;
	for (auto Toy : Toys)
	{
		if (auto CastedToy = Cast<AWPPetToy>(Toy))
		{
			CastedToy->OnToyCollected.AddUObject(this, &ThisClass::OnToyCollectedHandle);
		}
	}
}

void AWPGameStateBase::OnToyCollectedHandle(EToyType InToyType)
{
	if (ToysCollection.ToysCollection.Contains(InToyType))
	{
		auto CurrentValue = *ToysCollection.ToysCollection.Find(InToyType);
		CurrentValue++;
		ToysCollection.ToysCollection.Emplace(InToyType, CurrentValue);
	} else
	{
		ToysCollection.ToysCollection.Add(InToyType, 1);
	}
	OnToysCollectionUpdated.ExecuteIfBound(ToysCollection);
}
