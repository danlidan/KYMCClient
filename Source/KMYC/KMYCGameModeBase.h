// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "KMYCGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class KMYC_API AKMYCGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	
	virtual void StartPlay() override;
};
