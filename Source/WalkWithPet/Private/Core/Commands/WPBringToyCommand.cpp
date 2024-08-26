// Fill out your copyright notice in the Description page of Project Settings.

#include "Core/Commands/WPBringToyCommand.h"
#include "Core/Pet/WPPetPawn.h"
#include "Core/Pet/Toys/WPPetToy.h"

void UWPBringToyCommand::Run()
{
	if (!CommandContext.Target || !CommandContext.PetPawn)
	{
		Failed();
		return;
	}
	CommandContext.PetPawn->WalkToTarget(CommandContext.Target);
	CommandContext.PetPawn->OnActionFailed.AddDynamic(this, &ThisClass::Failed);
	CommandContext.PetPawn->OnActionSucceeded.AddDynamic(this, &ThisClass::BringToy);
}

void UWPBringToyCommand::Succeeded()
{
	if (CommandContext.Target)
	{
		CommandContext.Target->Collect();
	}
	
	Super::Succeeded();
}

void UWPBringToyCommand::Failed()
{
	if (CommandContext.PetPawn)
	{
		CommandContext.PetPawn->StopWalk();
	}

	if (CommandContext.Target && CommandContext.PetPawn && CommandContext.Target->IsAttachedTo(CommandContext.PetPawn))
	{
		CommandContext.Target->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	}
	
	Super::Failed();
}

void UWPBringToyCommand::BringToy()
{
	if (!CommandContext.Target || !CommandContext.PetPawn)
	{
		Failed();
		return;
	}
	CommandContext.PetPawn->OnActionSucceeded.Remove(this, "BringToy");
	CommandContext.Target->AttachToActor(CommandContext.PetPawn, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	CommandContext.PetPawn->WalkToTarget(CommandContext.Owner);
	CommandContext.PetPawn->OnActionSucceeded.AddDynamic(this, &ThisClass::Succeeded);
}
