// Fill out your copyright notice in the Description page of Project Settings.

#include "LevelGenerator.h"
#include "Runtime/Core/Public/Math/UnrealMathUtility.h"
#include "Kismet/GameplayStatics.h"
#include "PropSpawnPoint.h"
#include "Engine/World.h"
#include "Engine/GameEngine.h"


// Sets default values
ALevelGenerator::ALevelGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALevelGenerator::BeginPlay()
{
	Super::BeginPlay();
	GenerateLevel();
}
void ALevelGenerator::SpawnIED(FVector spawnPoint)
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("IED SPAWNED"));
}

void ALevelGenerator::SpawnProp(FVector spawnPoint)
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("prop Spawned"));
}

TArray<AActor*> ALevelGenerator::FindAllSpawnPoints()
{
	TArray<AActor *> retVal;
	TSubclassOf<AActor> classToFind;
	classToFind = AActor::StaticClass();
	TArray<AActor*> foundSpawns;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), classToFind, foundSpawns);

	TSubclassOf<UPropSpawnPoint> componentClassToFind;
	componentClassToFind = UPropSpawnPoint::StaticClass();
	TArray<UPropSpawnPoint> foundComponents;
	for (int i = 0; i < foundSpawns.Num(); i++)
	{
		foundSpawns[i]->GetComponentsByClass<componentClassToFind>(foundComponents);
		if (foundSpawns.Num() != 0)
		{
			retVal.Add(foundSpawns[i]);
		}
		foundComponents = TArray<UPropSpawnPoint>();
	}
	return retVal;
}
// Called every frame
void ALevelGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ALevelGenerator::GenerateLevel()
{
	TArray<AActor *> spawnPoints = FindAllSpawnPoints();
	int numberOfSpawnLocations = spawnPoints.Num();
	int spawned = 0;
	int ToBeSpawned = (int)(propSpawnRate / 100.0f * numberOfSpawnLocations);
	while (spawned < ToBeSpawned)
	{
		FMath::RandRange(0, 100) <= percentageOfIEDS ? SpawnIED(spawnPoints[spawned]->GetTransform().GetLocation()) : SpawnProp(spawnPoints[spawned]->GetTransform().GetLocation());
		spawned++;
	}

}
