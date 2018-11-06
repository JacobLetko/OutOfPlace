// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Room.h"
#include "Components/ActorComponent.h"
#include "LevelGenerator.generated.h"

	UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
		class KIDNEXTDOOR_API ULevelGenerator : public UActorComponent
	{
		GENERATED_BODY()

	public:
		// Sets default values for this component's properties
		ULevelGenerator();

	protected:
		// Called when the game starts
		virtual void BeginPlay() override;
		void SpawnIED(FVector spawnPoint);
		void SpawnProp(FVector spawnPoint);
	public:
		// Called every frame
		virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
		UPROPERTY(EditAnywhere)
			// number of bombs
			int targetNumberOfIEDS;
		UPROPERTY(EditAnywhere, meta = (ClampMin = "0.0", ClampMax = "100.0", UIMin = "0.0", UIMax = "100.0"))
			float propSpawnRate;
		UPROPERTY(EditAnywhere, meta = (ClampMin = "0.0", ClampMax = "100.0", UIMin = "0.0", UIMax = "100.0"))
			float percentageOfIEDS;
		UPROPERTY(EditAnywhere)
			// Rooms in level
			TArray<URoom *> rooms;
		UPROPERTY(EditAnywhere)
			// Props to be spawned
			TArray<AActor *> IEDS;
		UPROPERTY(EditAnywhere)
			// Props to be spawned
			TArray<AActor *> props;
		virtual void GenerateLevel();

	};