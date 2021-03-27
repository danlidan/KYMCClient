// Fill out your copyright notice in the Description page of Project Settings.


#include "UDPSocket.h"
#include "SocketSubsystem.h"
#include "Networking/Public/Common/UdpSocketBuilder.h"

bool UUDPSocket::startUDPsocket(const FString& localIP, const FString& remoteIP, const int32& remotePort)
{
	RemoteAddr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	bool tmpvalid = 0;

	RemoteAddr->SetIp(*remoteIP,tmpvalid);
	RemoteAddr->SetPort(remotePort);

	UdpSocket = FUdpSocketBuilder("udp manager")
		.AsReusable()
		.WithBroadcast()/////////////广播  
		.WithSendBufferSize(2 * 1024 * 1024)
		.WithReceiveBufferSize(2 * 1024 * 1024)
		//.BoundToEndpoint(Endpoint)  
		;
	if (UdpSocket) {
		ScreenMsg("udpsocket initialized!");
	}
	return true;
}

void UUDPSocket::SendMsg(std::string msgSend)
{
	if (!UdpSocket) {
		ScreenMsg("No sender socket");
	}

	uint8* SendArray = (uint8*)msgSend.c_str();
	int32 len = msgSend.length();
	int32 BytesSent = 0;

	UdpSocket->SendTo(SendArray, len, BytesSent, *RemoteAddr);
}

void UUDPSocket::Recv(std::string& res)
{
	int32 BufferSize = 1048576;
	uint32 size = 0;

	if (UdpSocket && UdpSocket->HasPendingData(size)) {
		int32 read = 0;
		TArray<uint8> ReceivedData;//定义一个接收器  
		ReceivedData.SetNumUninitialized(FMath::Min(size, 65507u));
		UdpSocket->Recv(ReceivedData.GetData(), ReceivedData.Num(), read);
		if (read > 0) {
			uint8 ansiiData[2048];
			memcpy(ansiiData, ReceivedData.GetData(), read);//拷贝数据到接收器  
			ansiiData[read] = 0;                            //判断数据结束

			std::string tmp(read, 'a');
			for (int i = 0; i < read; ++i) tmp[i] = ansiiData[i];
			res = tmp;

			//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("recv udp data len %d"), res.length()));
		}
	}

	return;
}
