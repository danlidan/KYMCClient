// Copyright Epic Games, Inc. All Rights Reserved.


#include "KMYCGameModeBase.h"
#include "Kismet/GameplayStatics.h"

void AKMYCGameModeBase::StartPlay()
{
	Super::StartPlay();

	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello World, this is FPSGameMode!"));

	//UGameplayStatics::OpenLevel(GetWorld(), TEXT("World'/Game/Maps/BattleField.BattleField'"), 1);
}
