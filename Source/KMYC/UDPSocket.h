// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UDPSocket.generated.h"

/**
 * 
 */
UCLASS()
class KMYC_API UUDPSocket : public UObject
{
	GENERATED_BODY()

public:
	class FSocket *UdpSocket;

	TSharedPtr<FInternetAddr> RemoteAddr;

	//参数为远方的
	bool startUDPsocket(const FString& localIP, const FString& remoteIP, const int32& remotePort);

	//发送消息用
	void SendMsg(std::string msg);

	//用于消息接收
	void Recv(std::string& res);


	FORCEINLINE void ScreenMsg(const FString& Msg)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, *Msg);
	}

};
