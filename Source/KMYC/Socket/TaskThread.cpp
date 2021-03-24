// Fill out your copyright notice in the Description page of Project Settings.


#include "TaskThread.h"
#include "../testChar/MyTestCharacter.h"

TaskThread::TaskThread()
{
}

TaskThread::TaskThread(AMyTestCharacter* T) : testChar(T)
{

}

TaskThread::~TaskThread()
{
}

bool TaskThread::Init()
{
	return true;
}

uint32 TaskThread::Run()
{
	testChar->receiveMove();
	return 1;
}

void TaskThread::Stop()
{

}

void TaskThread::Exit()
{

}
