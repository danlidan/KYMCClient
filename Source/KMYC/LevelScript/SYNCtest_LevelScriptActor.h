// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "Engine/EngineTypes.h"
#include "SYNCtest_LevelScriptActor.generated.h"

/**
 * 
 */
UCLASS()
class KMYC_API ASYNCtest_LevelScriptActor : public ALevelScriptActor
{
	GENERATED_BODY()
	
public:
	ASYNCtest_LevelScriptActor();
	//~ASYNCtest_LevelScriptActor();
	virtual void BeginPlay() override;

	virtual void Tick(float detalTime) override;

	class AUDPSend *UDPsender;

	//class FRunnableThread *RecvThread;
	class AUDPRecive *Recvier;

	FTimerHandle timerHandle;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class AMyTestCharacter *testChar = nullptr;

	void SendTest();
};
