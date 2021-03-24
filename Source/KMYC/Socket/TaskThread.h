// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class KMYC_API TaskThread : public FRunnable
{
public:
	TaskThread();
	TaskThread(class AMyTestCharacter* T);
	~TaskThread();

	bool Init();

	uint32 Run();

	void Stop();

	void Exit();

	class AMyTestCharacter *testChar;
};
