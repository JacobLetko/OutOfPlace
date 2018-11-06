// Fill out your copyright notice in the Description page of Project Settings.

#include "LevelGenerator.h"
#include "Room.h"


// Sets default values for this component's properties
ULevelGenerator::ULevelGenerator()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void ULevelGenerator::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void ULevelGenerator::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void ULevelGenerator::GenerateLevel()
{
	/*
	int numberOfSpawnLocations = 0;
	TArray<FVector> spawnPoints;
	for (int i = 0; i < rooms.Num(); i++)
	{
		if (rooms[i] != nullptr)
		{
			numberOfSpawnLocations += rooms[i]->SpawnPoints.Num;
			while(rooms[i]->CanSpawn())
			{
				//unload spawn points from room
				spawnPoints.Add(rooms[i]->Spawn());
			}
		}
	}
	if (numberOfSpawnLocations >= targetNumberOfIEDS)
	{
		int spawned = 0;
		while (spawned < spawnPoints)
		{
			SpawnIED(spawnPoints[spawned]);
		}
		for (; spawned < spawnPoints)

	}*/
}

