// Fill out your copyright notice in the Description page of Project Settings.

#include "Core/Pet/Toys/WPPetToy.h"
#include "Kismet/GameplayStatics.h"

AWPPetToy::AWPPetToy()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AWPPetToy::Collect()
{
	OnToyCollected.Broadcast(ToyType);
	UGameplayStatics::PlaySound2D(this,CollectSound);
	OnToyCollected.Clear();
	Destroy();
}

void AWPPetToy::BeginPlay()
{
	Super::BeginPlay();
	
	checkf(ToyType != EToyType::None, TEXT("FOR %s TOY TYPE IS NONE"), *GetName());
}
