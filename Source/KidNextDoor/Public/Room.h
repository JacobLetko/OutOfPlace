// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Room.generated.h"
	UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
		class KIDNEXTDOOR_API URoom : public UActorComponent
	{
		GENERATED_BODY()

	public:
		// Sets default values for this component's properties
		URoom();

	protected:
		// Called when the game starts
		virtual void BeginPlay() override;

	public:
		// Called every frame
		virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
		// Holds spawn points
		UPROPERTY(EditAnywhere) TArray<AActor *> SpawnPoints;
		bool CanSpawn();
		FVector Spawn();
	};