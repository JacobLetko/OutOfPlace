// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "KidNextDoorGameMode.h"
#include "KidNextDoorHUD.h"
#include "KidNextDoorCharacter.h"
#include "UObject/ConstructorHelpers.h"

AKidNextDoorGameMode::AKidNextDoorGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AKidNextDoorHUD::StaticClass();
}
