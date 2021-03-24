// Fill out your copyright notice in the Description page of Project Settings.


#include "GameLevelScriptActor.h"
#include "../KMYCInstance.h"
#include "../Character/OriginCharacter.h"
#include "../Msg/game.pb.h"
#include "Sockets.h"
#include "IPAddress.h"
#include "SocketSubsystem.h"
#include "../UDPSocket.h"

void AGameLevelScriptActor::BeginPlay()
{
	PrimaryActorTick.bCanEverTick = true;

	Super::BeginPlay();

	//建立udp发送
	Udpmanager = NewObject<UUDPSocket>();
	Udpmanager->startUDPsocket("127.0.0.1", "127.0.0.1", 19313);

	//todo:发送帧0，通知udp地址
	for (int i = 0; i < 5; ++i) {
		SendFrame("hello");
	}

	//初始化各个参数
	GInstance = Cast<UKMYCInstance>(GetGameInstance());

	playerNum = GInstance->playerNum;
	myPlayerId = GInstance->myPlayerId;
	players.SetNum(playerNum);

	//初始化每个玩家的生成位置和旋转
	startLocation.SetNum(playerNum);
	for (int i = 0; i < playerNum/2; ++i) {
		startLocation[i] = FVector(0, i * 300.0, 180);
	}
	for (int i = playerNum / 2; i < playerNum; ++i) {
		startLocation[i] = FVector(1000, (i-playerNum/2) * 300.0, 180);
	}
	startRotation.SetNum(playerNum);
	for (int i = 0; i < playerNum; ++i) {
		startRotation[i] = FRotator(0, 0, 0);
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("my playerid %d"), myPlayerId));
	//在对应位置和旋转生成
	for (int i = 0; i < playerNum; ++i) {
		players[i] = GetWorld()->SpawnActor<AOriginCharacter>(OriginCharClass, startLocation[i], startRotation[i]);
	}
	//控制权交给当前玩家
	GetWorld()->GetFirstPlayerController()->Possess(players[myPlayerId]);


	//-----------------------------------------------
	//以下为测试
	
}

void AGameLevelScriptActor::Tick(float DeltaTime)
{
	if (Udpmanager) {
		RecvMsg();
	}
}

void AGameLevelScriptActor::SendFrame(const std::string& testInfo)
{
	msg::Frame A;
	A.set_testinfo(testInfo);
	std::string a = A.SerializeAsString();
	int32 msglen = a.length();

	Udpmanager->SendMsg(Int32ToStr16(msglen) + a);
}

std::string AGameLevelScriptActor::Int32ToStr16(int32 val)
{
	std::string a = "aa";
	a[1] = (char)val;

	val >>= 8;
	a[0] = (char)val;

	return a;
}

int32 AGameLevelScriptActor::Str16ToInt32(std::string s)
{
	int32 ret = (int32)s[1] + (((int32)s[0]) << 8);
	return ret;
}

//每帧接收消息
void AGameLevelScriptActor::RecvMsg()
{
	std::string recvData;
	Udpmanager->Recv(recvData);

	int32 msglen = recvData.length();
	int32 curlen = 0;
	while (curlen < msglen) {
		int32 len = Str16ToInt32(recvData.substr(curlen, 2));

		HandleFrames(recvData.substr(curlen + 2));

		curlen += len + 2;
	}
}

//处理帧
void AGameLevelScriptActor::HandleFrames(const std::string& message)
{
	msg::Frame data;
	data.ParseFromString(message);

	FString tmpStr(data.testinfo().c_str());

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, tmpStr);
}
