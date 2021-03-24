// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelScriptActor_Login.h"
#include "../KMYCInstance.h"
#include "Templates/Casts.h"

void ALevelScriptActor_Login::BeginPlay()
{
	Super::BeginPlay();

	GameInstance = Cast<UKMYCInstance>(GetGameInstance());
}
