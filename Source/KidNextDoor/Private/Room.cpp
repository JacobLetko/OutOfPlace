// Fill out your copyright notice in the Description page of Project Settings.

#include "Room.h"
#include "Runtime/Core/Public/Math/UnrealMathUtility.h"
#include "GameFramework/Actor.h"


// Sets default values for this component's properties
URoom::URoom()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URoom::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void URoom::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool URoom::CanSpawn()
{
	if (SpawnPoints.Num > 0)
	{
		return true;
	}
	return false;
}

FVector URoom::Spawn()
{
	if (CanSpawn())
	{
		/*int rand = FMath::RandRange(0, SpawnPoints.Num - 1);
		FVector retVal = SpawnPoints[rand]->GetTransform.GetLocation();
		SpawnPoints.RemoveAt(rand);
		return retVal;*/
	}
	return FVector();
}

