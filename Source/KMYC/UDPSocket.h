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

	//����ΪԶ����
	bool startUDPsocket(const FString& localIP, const FString& remoteIP, const int32& remotePort);

	//������Ϣ��
	void SendMsg(std::string msg);

	//������Ϣ����
	void Recv(std::string& res);


	FORCEINLINE void ScreenMsg(const FString& Msg)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, *Msg);
	}

};
