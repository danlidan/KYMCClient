// Fill out your copyright notice in the Description page of Project Settings.


#include "UDPSend.h"
#include "Common/UdpSocketBuilder.h"

// Sets default values
AUDPSend::AUDPSend()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SenderSocket = NULL;
	ShowOnScreenDebugMessages = true;
}

// Called when the game starts or when spawned
void AUDPSend::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUDPSend::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AUDPSend::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	//~~~~~~~~~~~~~~~~  
	if (SenderSocket) //Clear all sockets!  
	{
		SenderSocket->Close();
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(SenderSocket);
	}
}
bool AUDPSend::RamaUDPSender_SendString(FString ToSend)                 //发送消息处理  
{
	if (!SenderSocket)
	{
		ScreenMsg("No sender socket");
		return false;
	}
	//~~~~~~~~~~~~~~~~  
	//发送消息  
	int32 BytesSent = 0;
	FString serialized = ToSend;
	TCHAR *serializedChar = serialized.GetCharArray().GetData();
	int32 size = FCString::Strlen(serializedChar);
	int32 sent = 0;
	//SenderSocket->SendTo(Writer.GetData(), Writer.Num(), BytesSent, *RemoteAddr);  
	SenderSocket->SendTo((uint8*)TCHAR_TO_UTF8(serializedChar), size, BytesSent, *RemoteAddr);//发送给远端地址  
	if (BytesSent <= 0)
	{
		const FString Str = "Socket is valid but the receiver received 0 bytes, make sure it is listening properly!";
		UE_LOG(LogTemp, Error, TEXT("%s"), *Str);
		ScreenMsg(Str);
		return false;
	}
	ScreenMsg("UDP Send Succcess! INFO Sent = ", ToSend);
	return true;
}


void AUDPSend::SendMsg(std::string msgSend)
{
	if (!SenderSocket) {
		ScreenMsg("No sender socket");
	}

	uint8* SendArray = (uint8*)msgSend.c_str();
	int32 len = msgSend.length();
	int32 BytesSent = 0;

	SenderSocket->SendTo(SendArray, len, BytesSent, *RemoteAddr);
}

bool AUDPSend::StartUDPSender(const FString & YourChosenSocketName, const FString & TheIP, const int32 ThePort, bool UDP)///////////初始化远端IP 发送信息前  
{
	//FIPv4Endpoint Endpoint(FIPv4Address::Any, 6789);  
	//Create Remote Address.  
	RemoteAddr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	bool bIsValid;
	RemoteAddr->SetIp(*TheIP, bIsValid);
	RemoteAddr->SetPort(ThePort);
	if (!bIsValid)
	{
		ScreenMsg("Rama UDP Sender>> IP address was not valid!", TheIP);
		return false;
	}
	SenderSocket = FUdpSocketBuilder(*YourChosenSocketName)
		.AsReusable()
		.WithBroadcast()/////////////广播  
		.WithSendBufferSize(2 * 1024 * 1024)
		//.BoundToEndpoint(Endpoint)  
		;
	
	int32 SendSize = 2 * 1024 * 1024;
	SenderSocket->SetSendBufferSize(SendSize, SendSize);
	SenderSocket->SetReceiveBufferSize(SendSize, SendSize);
	if (bIsValid)
	{
		bIsValid = true;
	}

	if (SenderSocket) {

	}
	return bIsValid;
}

