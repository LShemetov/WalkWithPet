// Fill out your copyright notice in the Description page of Project Settings.

#include "Core/Pet/WPPetPawn.h"
#include "Core/Components/WPCommandReceiverComponent.h"

AWPPetPawn::AWPPetPawn()
{
	PrimaryActorTick.bCanEverTick = false;

	CommandReceiverComponent = CreateDefaultSubobject<UWPCommandReceiverComponent>("CommandReceiverComponent");
	checkf(CommandReceiverComponent, TEXT("Command Receiver Component Not Initialized"));
}
