// Fill out your copyright notice in the Description page of Project Settings.

#include "Core/Commands/WPCommand.h"

#include "Core/Pet/WPPetPawn.h"

void UWPCommand::Stop()
{
	if (bIsCompleted)
	{
		return;
	}
	Failed();
}

void UWPCommand::Succeeded()
{
	bIsCompleted = true;
	if (CommandContext.PetPawn)
	{
		//CommandContext.PetPawn->OnActionSucceeded.RemoveAll(this);
		//CommandContext.PetPawn->OnActionFailed.RemoveAll(this);
	}
	OnStopped.ExecuteIfBound();
}

void UWPCommand::Failed()
{
	bIsCompleted = false;
	if (CommandContext.PetPawn)
	{
		//CommandContext.PetPawn->OnActionSucceeded.RemoveAll(this);
		//CommandContext.PetPawn->OnActionFailed.RemoveAll(this);
	}
	OnStopped.ExecuteIfBound();
}
