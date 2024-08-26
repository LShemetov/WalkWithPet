// Fill out your copyright notice in the Description page of Project Settings.

#include "Core/Commands/WPComeToMeCommand.h"
#include "Core/Pet/WPPetPawn.h"

void UWPComeToMeCommand::Run()
{
	if (!CommandContext.Owner || !CommandContext.PetPawn)
	{
		Failed();
		return;
	}
	CommandContext.PetPawn->WalkToTarget(CommandContext.Owner);
	CommandContext.PetPawn->OnActionSucceeded.AddDynamic(this, &ThisClass::Succeeded);
	CommandContext.PetPawn->OnActionFailed.AddDynamic(this, &ThisClass::Failed);
}

void UWPComeToMeCommand::Failed()
{
	if (CommandContext.PetPawn)
	{
		CommandContext.PetPawn->StopWalk();
	}
	
	Super::Failed();
}
