// Fill out your copyright notice in the Description page of Project Settings.

#include "Core/Player/WPPlayerPawn.h"
#include "Core/Player/WPPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "Core/Commands/WPCommand.h"
#include "Core/Components/WPCommandReceiverComponent.h"
#include "Core/Pet/WPPetPawn.h"
#include "Data/WPCoreTypes.h"
#include "Kismet/GameplayStatics.h"
#include "UI/WPMainWidget.h"

void AWPPlayerPawn::BeginPlay()
{
	Super::BeginPlay();

	if (!MainWidgetClass) return;
	if ((MainWidget = Cast<UWPMainWidget>(CreateWidget(GetWorld(), MainWidgetClass))))
	{
		MainWidget->AddToViewport();
		MainWidget->OnCommandButtonClicked.BindUObject(this, &AWPPlayerPawn::AcceptCommandRequest);
	}
	
	PetPawn = Cast<AWPPetPawn>(UGameplayStatics::GetActorOfClass(this, AWPPetPawn::StaticClass()));
	if (!PetPawn) return;

	PlayerController = Cast<AWPPlayerController>(GetController());
	if (PlayerController)
	{
		PlayerController->OnMouseClicked.AddDynamic(this, &ThisClass::ChangeTarget);
	}
}

void AWPPlayerPawn::AcceptCommandRequest(TSubclassOf<UWPCommand> CommandClass)
{
	if (!CommandClass) return;
	if (PlayerController && PetPawn)
	{
		auto CommandReceiverComponent = PetPawn->GetCommandReceiverComponent();
		if (!CommandReceiverComponent) return;

		CommandReceiverComponent->ExecuteCommand(CommandClass, FCommandContext(this, PlayerController->GetTarget(), PetPawn));
	}
}

void AWPPlayerPawn::ChangeTarget()
{
	if (MainWidget && PlayerController)
	{
		MainWidget->SetTarget(PlayerController->GetTarget());
	}
}
