// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/WPCommandButton.h"

#include "Components/Button.h"
#include "Data/WPButtonInfo.h"
#include "Data/WPListObjectData.h"

void UWPCommandButton::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);

	ObjectData = Cast<UWPListObjectData>(ListItemObject);
	if (ObjectData)
	{
		Text->SetText(ObjectData->GetObjectData().CommandName);
		Button->OnClicked.AddDynamic(this, &ThisClass::OnClickedHandle);
	}
}

void UWPCommandButton::OnClickedHandle()
{
	if(ObjectData)
	{
		ObjectData->OnClicked.ExecuteIfBound(ObjectData);
	}
}
