// Fill out your copyright notice in the Description page of Project Settings.


#include "UDPReciveThread.h"
#include "../UDPRecive.h"
#include "../testChar/MyTestCharacter.h"
#include "TaskThread.h"

UDPReciveThread::UDPReciveThread():TestChar(nullptr) {

}

UDPReciveThread::UDPReciveThread(AMyTestCharacter *T): TestChar(T){

}

UDPReciveThread::~UDPReciveThread()
{
	if (Recvier) {
		delete Recvier;
		Recvier = nullptr;
	}
}

bool UDPReciveThread::Init()
{
	Recvier = Cast<AUDPRecive>(NewObject<AUDPRecive>());
	bool recvSuc = false;
	Recvier->StartUDPReceiver("testReciver", "127.0.0.1", 10008, recvSuc);
	if (!recvSuc) {
		UE_LOG(LogTemp, Warning, TEXT("UDP recive Connect Failed!"));
		delete Recvier;
		Recvier = nullptr;
	}

	stopping = false;
	return 1;
}

uint32 UDPReciveThread::Run()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("running "));
	while (!stopping && Recvier) {
		FString Rcvdata;
		bool RcvSuc;
		Recvier->DataRecv(Rcvdata, RcvSuc);
		if (RcvSuc) {
			FRunnableThread::Create(new TaskThread(TestChar), TEXT("recvThread"));
		}
		//
	}
	return 1;
}

void UDPReciveThread::Stop()
{
	stopping = true;
}

void UDPReciveThread::Exit()
{
	
}
