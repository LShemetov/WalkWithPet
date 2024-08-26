// Fill out your copyright notice in the Description page of Project Settings.

#include "Core/Components/WPCommandReceiverComponent.h"
#include "Core/Commands/WPCommand.h"
#include "Data/WPCoreTypes.h"

UWPCommandReceiverComponent::UWPCommandReceiverComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UWPCommandReceiverComponent::ExecuteCommand(TSubclassOf<UWPCommand> CommandClass, FCommandContext CommandContext)
{
	if (!CommandClass) return;
	ExecutableCommand = NewObject<UWPCommand>(GetOwner(), CommandClass);
	if (ExecutableCommand)
	{
		ExecutableCommand->SetCommandContext(CommandContext);
	}
	!RunningCommand ? NextCommand() : RunningCommand->Stop();
}

void UWPCommandReceiverComponent::NextCommand()
{
	if (RunningCommand)
	{
		RunningCommand->OnStopped.Unbind();
		RunningCommand = nullptr;
	}
	if (ExecutableCommand)
	{
		RunningCommand = ExecutableCommand;
		RunningCommand->Run();
		RunningCommand->OnStopped.BindUObject(this, &ThisClass::NextCommand);
		ExecutableCommand = nullptr;
	}
}
