// Fill out your copyright notice in the Description page of Project Settings.


#include "GameLevelScriptActor.h"
#include "../KMYCInstance.h"
#include "../Character/OriginCharacter.h"
#include "../Msg/game.pb.h"
#include "Sockets.h"
#include "IPAddress.h"
#include "SocketSubsystem.h"
#include "../UDPSocket.h"
#include "../Msg/protoId.pb.h"

void AGameLevelScriptActor::BeginPlay()
{
	PrimaryActorTick.bCanEverTick = true;

	Super::BeginPlay();

	//建立udp发送
	Udpmanager = NewObject<UUDPSocket>();
	Udpmanager->startUDPsocket("127.0.0.1", "127.0.0.1", 19313);

	//初始化各个参数
	GInstance = Cast<UKMYCInstance>(GetGameInstance());

	//各种初始化，syncid设为-1
	playerNum = GInstance->playerNum;
	myPlayerId = GInstance->myPlayerId;
	roomId = GInstance->roomId;
	lastFrameOpts = nullptr;
	syncId = -1;
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
		players[i]->name = FString(GInstance->playerName[i].c_str());
		players[i]->rank = GInstance->playerRank[i];
		players[i]->playerId = i;
	}
	//控制权交给当前玩家
	GetWorld()->GetFirstPlayerController()->Possess(players[myPlayerId]);

	//todo:发送帧0，通知udp地址
	SendFrame();


	//-----------------------------------------------
	//以下为测试
	
}

void AGameLevelScriptActor::Tick(float DeltaTime)
{
	if (Udpmanager) {
		RecvMsg();
	}
}

//发送消息的格式为NextFrameOpts
void AGameLevelScriptActor::SendFrame()
{
	msg::NextFrameOpts A;
	//发送帧号为syncId+1
	A.set_frameid(syncId+1);
	A.set_playerid(myPlayerId);
	A.set_roomid(roomId);

	//收集当前帧该玩家的移动操作
	AOriginCharacter* myPlayer = players[GInstance->myPlayerId];
	msg::OptionEvent *moveOpts = A.add_opts();
	moveOpts->set_playerid(myPlayerId);
	moveOpts->set_opttype(msg::OptionType::MoveId);
	moveOpts->set_eastvalue(myPlayer->EastValue);
	moveOpts->set_northvalue(myPlayer->NorthValue);
	
	//

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

int32 AGameLevelScriptActor::Str16ToInt32(const std::string& s)
{
	int32 ret = (int32)s[1] + (((int32)s[0]) << 8);
	return ret;
}

//每帧接收消息接收的消息格式为LogicFrame
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

//处理帧LogicFrame
void AGameLevelScriptActor::HandleFrames(const std::string& message)
{
	msg::LogicFrame data;
	data.ParseFromString(message);

	//若frameid<=syncid跳过
	if (data.frameid() <= syncId) return;

	//todo同步自己客户端上一帧逻辑操作
	if (lastFrameOpts != nullptr) {
		SyncLastFrame(*lastFrameOpts);
	}

	//todo接受从syncid+1到frameid-1的操作



	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("recv frame id %d syncId %d"), data.frameid(), syncId));
	syncId = data.frameid();


	//获取最后一个操作（frameid）
	if (data.unsyncframes_size() > 0) {
		//跟新lastFrameOpts
		delete lastFrameOpts;
		lastFrameOpts = new class msg::FrameOpts(data.unsyncframes(data.unsyncframes_size() - 1));
		//处理该帧动画
		HandleFrameEvent(*lastFrameOpts);
	}

	//发送自己当前帧的操作
	SendFrame();
}

void AGameLevelScriptActor::SyncLastFrame(const class msg::FrameOpts& data)
{

}

void AGameLevelScriptActor::HandleFrameEvent(const class msg::FrameOpts& data)
{
	for (auto i = 0; i < data.opts_size(); ++i) {
		msg::OptionEvent opt = data.opts(i);
		switch (opt.opttype()) {
		//处理人物移动动画
		case msg::OptionType::MoveId:
			FVector EastDirection(1, 0, 0);
			FVector NorthDirection(0, -1, 0);
			if (opt.playerid() < playerNum && players[opt.playerid()]) {
				AOriginCharacter* tmpPlayer = players[opt.playerid()];
				tmpPlayer->SyncEastValue = opt.eastvalue();
				tmpPlayer->SyncNorthValue = opt.northvalue();
			}
			break;
		}
	}
}
