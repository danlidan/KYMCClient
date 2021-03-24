// Fill out your copyright notice in the Description page of Project Settings.


#include "SYNCtest_LevelScriptActor.h"
#include "../UDPSend.h"
#include "../UDPRecive.h"
#include "../Socket/UDPReciveThread.h"
#include "../testChar/MyTestCharacter.h"
#include "HAL/RunnableThread.h"

ASYNCtest_LevelScriptActor::ASYNCtest_LevelScriptActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

/*
ASYNCtest_LevelScriptActor::~ASYNCtest_LevelScriptActor()
{
	if (RecvThread) {
		RecvThread->Kill(true);
		delete RecvThread;
	}
}
*/

void ASYNCtest_LevelScriptActor::BeginPlay()
{
	

	//首先建立udp发送=
	UDPsender = Cast<AUDPSend>(NewObject<AUDPSend>());
	bool sendSuc = UDPsender->StartUDPSender("testSender", "127.0.0.1", 10007, 1);
	//在蓝图的beginplay中生成角色并初始化它，之后testChar不为nil
	Super::BeginPlay();
	
	//if(testChar) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::SanitizeFloat(testChar->testV));
	//建立接收的监听
	if (testChar) {
		//RecvThread = FRunnableThread::Create(new UDPReciveThread(testChar), TEXT("recvThread"));
		//RecvThread->SetThreadPriority(TPri_Highest);
		Recvier = Cast<AUDPRecive>(NewObject<AUDPRecive>());
		bool recvSuc = false;
		Recvier->StartUDPReceiver("testReciver", "127.0.0.1", 10008, recvSuc);
		//发送一条信息
		GetWorldTimerManager().SetTimer(timerHandle, this, &ASYNCtest_LevelScriptActor::SendTest, 5.0);
	}
}

void ASYNCtest_LevelScriptActor::Tick(float detalTime)
{
	//持续监听
	if (Recvier) {

		bool RcvSuc;
		FString Rcvdata;
		Recvier->DataRecv(Rcvdata, RcvSuc);
		if (RcvSuc) {
			testChar->receiveMove();
		}
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("failed!"));
	}
}

void ASYNCtest_LevelScriptActor::SendTest()
{
	UDPsender->RamaUDPSender_SendString("Hello");
}
