// Fill out your copyright notice in the Description page of Project Settings.


#include "Socket.h"
#include "Sockets.h"
#include "SocketSubsystem.h"
#include "Networking/Public/Interfaces/IPv4/IPv4Address.h"
#include "Containers/UnrealString.h"

USocket::USocket()
{
	CreateKMYCSocket("127.0.0.1", 19312);
}

//proto��Ϣ��ʽ�� len 2Byte | id 2Byte | protobuf message
//len Ϊ id + message�ĳ��ȣ�������len����
//len & id ��Ϊ��˱��룬 ����id������Ϣ����

void USocket::Send(std::string msg, int32 protoID)
{
	//get head
	int32 len = msg.length() + 2;
	std::string msgSend = Int32ToStr16(len) + Int32ToStr16(protoID) + msg;

	uint8* SendArray = (uint8*)msgSend.c_str();
	len = msgSend.length();

	//send
	int32 sent = 0;
	Host->Send(SendArray, len, sent);
}

void USocket::Recv(std::string& res)
{
	int32 BufferSize = 2048;
	uint32 size = 0;

	if (Host && Host->HasPendingData(size)) {
		int32 read = 0;
		TArray<uint8> ReceivedData;//����һ��������  
		ReceivedData.SetNumUninitialized(FMath::Min(size, 65507u));
		Host->Recv(ReceivedData.GetData(), ReceivedData.Num(), read);
		if (read > 0) {
			uint8 ansiiData[2048];
			memcpy(ansiiData, ReceivedData.GetData(), read);//�������ݵ�������  
			ansiiData[read] = 0;                            //�ж����ݽ���
			
			std::string tmp(read, 'a');
			for (int i = 0; i < read; ++i) tmp[i] = ansiiData[i];
			res = tmp;

			//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("recv data %d"), res.length()));
		}
	}

	return;
}

std::string USocket::Int32ToStr16(int32 val)
{
	std::string a = "aa";
	a[1] = (char)val;

	val >>= 8;
	a[0] = (char)val;

	return a;
}

int32 USocket::Str16ToInt32(std::string s)
{
	int32 ret = (int32)s[1] + (((int32)s[0]) << 8);
	return ret;
}

bool USocket::CreateKMYCSocket(FString IPStr, int32 port)
{
	FIPv4Address ip;
	FIPv4Address::Parse(IPStr, ip);     //�������IPStrתΪIPv4��ַ

	//����һ��addr���ip��ַ�Ͷ˿�
	TSharedPtr<FInternetAddr> addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	addr->SetIp(ip.Value);
	addr->SetPort(port);

	//�����ͻ���socket
	Host = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("default"), false);

	//���ӳɹ�
	if (Host->Connect(*addr))
	{
		UE_LOG(LogTemp, Warning, TEXT("Connect Succeed!"));
		return true;
	}
	//����ʧ��
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Connect Failed!"));
		return false;
	}

	
}
