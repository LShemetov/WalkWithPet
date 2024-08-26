// Fill out your copyright notice in the Description page of Project Settings.

#include "Core/Commands/WPGoForAWalkCommand.h"
#include "NavigationSystem.h"
#include "AI/Navigation/NavigationTypes.h"
#include "Core/Pet/WPPetPawn.h"

void UWPGoForAWalkCommand::Run()
{
	if (!CommandContext.Owner || !CommandContext.PetPawn)
	{
		Failed();
		return;
	}
	InitLocation = CommandContext.PetPawn->GetActorLocation();
	CommandContext.PetPawn->OnActionSucceeded.AddDynamic(this, &ThisClass::Succeeded);
	ChooseNewLocation();
}

void UWPGoForAWalkCommand::Succeeded()
{
	if (GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(WaitTimerHandle, this, &ThisClass::ChooseNewLocation, WaitTime, false);
	}
}

void UWPGoForAWalkCommand::Failed()
{
	if (CommandContext.PetPawn)
	{
		CommandContext.PetPawn->StopWalk();
	}
	if (GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(WaitTimerHandle);
	}
	
	Super::Failed();
}

FVector UWPGoForAWalkCommand::GenerateLocation()
{
	if (CommandContext.Owner)
	{
		if (UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld()))
		{
			FNavLocation ResultLocation;
			NavSys->GetRandomReachablePointInRadius(CommandContext.Owner->GetActorLocation(), Radius, ResultLocation);
			return ResultLocation.Location;
		}
		return CommandContext.Owner->GetActorLocation();
	}
	return InitLocation;
}

void UWPGoForAWalkCommand::ChooseNewLocation()
{
	CommandContext.PetPawn->WalkInLocation(GenerateLocation());
}
