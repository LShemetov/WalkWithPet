// Fill out your copyright notice in the Description page of Project Settings.

#include "Core/Commands/WPSitDownCommand.h"
#include "Core/Pet/WPPetPawn.h"

void UWPSitDownCommand::Run()
{
	if (!CommandContext.PetPawn)
	{
		Failed();
		return;
	}
	CommandContext.PetPawn->SetCrouchState(true);
	CommandContext.PetPawn->OnActionFailed.AddDynamic(this, &ThisClass::OnAnimFinishedHandle);
}

void UWPSitDownCommand::Failed()
{
	if (CommandContext.PetPawn)
	{
		CommandContext.PetPawn->SetCrouchState(false);
	}
	bIsCompleted = false;
}

void UWPSitDownCommand::OnAnimFinishedHandle()
{
	OnStopped.ExecuteIfBound();
}
