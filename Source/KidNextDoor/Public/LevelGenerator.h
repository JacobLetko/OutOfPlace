// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelGenerator.generated.h"

UCLASS()
class KIDNEXTDOOR_API ALevelGenerator : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this component's properties
	ALevelGenerator();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	void SpawnIED(FVector spawnPoint);
	void SpawnProp(FVector spawnPoint);
	TArray<AActor *> FindAllSpawnPoints();
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, meta = (ClampMin = "0.0", ClampMax = "100.0", UIMin = "0.0", UIMax = "100.0"))
		float propSpawnRate = 75;
	UPROPERTY(EditAnywhere, meta = (ClampMin = "0.0", ClampMax = "100.0", UIMin = "0.0", UIMax = "100.0"))
		float percentageOfIEDS = 30;
	UPROPERTY(EditAnywhere)
		// Props to be spawned
		TArray<AActor *> IEDS;
	UPROPERTY(EditAnywhere)
		// Props to be spawned
		TArray<AActor *> props;
	virtual void GenerateLevel();
};
