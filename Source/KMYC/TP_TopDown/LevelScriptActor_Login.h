// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "LevelScriptActor_Login.generated.h"

/**
 * 
 */
UCLASS()
class KMYC_API ALevelScriptActor_Login : public ALevelScriptActor
{
	GENERATED_BODY()

public:
	void BeginPlay();
	
	class UKMYCInstance *GameInstance;
};
