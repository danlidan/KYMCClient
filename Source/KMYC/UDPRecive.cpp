// Fill out your copyright notice in the Description page of Project Settings.


#include "UDPRecive.h"
#include "SocketSubsystem.h"
#include "Common/UdpSocketBuilder.h"
#include "Common/UdpSocketReceiver.h"

// Sets default values
AUDPRecive::AUDPRecive()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ListenSocket = NULL;
}

// Called when the game starts or when spawned
void AUDPRecive::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUDPRecive::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AUDPRecive::StartUDPReceiver(const FString& YourChosenSocketName, const FString& TheIP, const int32 ThePort, bool& success)
{
	TSharedRef<FInternetAddr> targetAddr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	FIPv4Address Addr;
	FIPv4Address::Parse(TheIP, Addr);
	//Create Socket  
	FIPv4Endpoint Endpoint(FIPv4Address::Any, ThePort);  //所有ip地址本地  
														 //FIPv4Endpoint Endpoint(Addr, ThePort);                 //指定ip地址  
	ListenSocket = FUdpSocketBuilder(*YourChosenSocketName)
		.AsNonBlocking()
		.AsReusable()
		.BoundToEndpoint(Endpoint)
		.WithReceiveBufferSize(2 * 1024 * 1024)
		;
	//BUFFER SIZE  
	int32 BufferSize = 2 * 1024 * 1024;
	ListenSocket->SetSendBufferSize(BufferSize, BufferSize);
	ListenSocket->SetReceiveBufferSize(BufferSize, BufferSize);
	if (!ListenSocket)
	{
		ScreenMsg("No socket");
		success = false;
	}
	if (ListenSocket)
	{
		ScreenMsg("The receiver is initialized");
		success = true;
	}
}

void AUDPRecive::DataRecv(FString& str, bool& success)
{
	if (!ListenSocket)
	{
		ScreenMsg("No sender socket");
		success = false;
		//return success;  
	}
	TSharedRef<FInternetAddr> targetAddr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	TArray<uint8> ReceivedData;//定义一个接收器  
	uint32 Size = 0;
	if (ListenSocket->HasPendingData(Size))
	{
		success = true;
		str = "";
		//uint8 *Recv = new uint8[Size];
		int32 BytesRead = 0;
		ReceivedData.SetNumUninitialized(FMath::Min(Size, 65507u));
		ListenSocket->RecvFrom(ReceivedData.GetData(), ReceivedData.Num(), BytesRead, *targetAddr);//创建远程接收地址  
		char ansiiData[1024];
		memcpy(ansiiData, ReceivedData.GetData(), BytesRead);//拷贝数据到接收器  
		ansiiData[BytesRead] = 0;                            //判断数据结束  
		FString debugData = ANSI_TO_TCHAR(ansiiData);         //字符串转换  
		str = debugData;
		// memset(ansiiData,0,1024);//清空   
	}
	else
	{
		success = false;
	}
}

void AUDPRecive::Recv(std::string& res)
{
	int32 BufferSize = 2048;
	uint32 size = 0;

	if (ListenSocket && ListenSocket->HasPendingData(size)) {
		int32 read = 0;
		TArray<uint8> ReceivedData;//定义一个接收器  
		ReceivedData.SetNumUninitialized(FMath::Min(size, 65507u));
		ListenSocket->Recv(ReceivedData.GetData(), ReceivedData.Num(), read);
		if (read > 0) {
			uint8 ansiiData[2048];
			memcpy(ansiiData, ReceivedData.GetData(), read);//拷贝数据到接收器  
			ansiiData[read] = 0;                            //判断数据结束

			std::string tmp(read, 'a');
			for (int i = 0; i < read; ++i) tmp[i] = ansiiData[i];
			res = tmp;

			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("recv udp data len %d"), res.length()));
		}
	}

	return;
}

void AUDPRecive::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	//~~~~~~~~~~~~~~~~  
	delete UDPReceiver;
	UDPReceiver = nullptr;
	//Clear all sockets!  
	//makes sure repeat plays in Editor dont hold on to old sockets!  
	if (ListenSocket)
	{
		ListenSocket->Close();
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(ListenSocket);
	}
}

