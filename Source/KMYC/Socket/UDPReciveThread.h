// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HAL/Runnable.h"

/**
 * 
 */
class KMYC_API UDPReciveThread : public FRunnable
{
public:
	UDPReciveThread();
	UDPReciveThread(class AMyTestCharacter *T);

	~UDPReciveThread();

	bool Init();

	uint32 Run();

	void Stop();

	void Exit();

	AMyTestCharacter *TestChar;
private:
	class AUDPRecive *Recvier;

	bool stopping;
};
