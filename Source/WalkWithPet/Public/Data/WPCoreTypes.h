#pragma once

#include "CoreMinimal.h"
#include "WPCoreTypes.generated.h"

class AWPPetToy;
class AWPPetPawn;

USTRUCT()
struct FCommandContext
{
	GENERATED_BODY()

	UPROPERTY()
	TObjectPtr<APawn> Owner;

	UPROPERTY()
	AWPPetToy* Target = nullptr;

	UPROPERTY()
	TObjectPtr<AWPPetPawn> PetPawn;
};

UENUM(BlueprintType)
enum class EToyType : uint8
{
	None,
	Bear,
	Rabbit,
	Wolf,
	Fox
};

USTRUCT(BlueprintType)
struct FToysCollection
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	TMap<EToyType, int32> ToysCollection;
	
};
