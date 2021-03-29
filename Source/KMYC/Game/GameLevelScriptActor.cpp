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
#include "GameFramework/Actor.h"
#include "Components/CapsuleComponent.h"

void AGameLevelScriptActor::BeginPlay()
{
	PrimaryActorTick.bCanEverTick = true;
	
	Super::BeginPlay();

	//����udp����
	Udpmanager = NewObject<UUDPSocket>();
	Udpmanager->startUDPsocket("127.0.0.1", "127.0.0.1", 19313);

	//��ʼ����������
	GInstance = Cast<UKMYCInstance>(GetGameInstance());

	//���ֳ�ʼ����syncid��Ϊ-1
	playerNum = GInstance->playerNum;
	myPlayerId = GInstance->myPlayerId;
	roomId = GInstance->roomId;
	lastFrameOpts = nullptr;
	syncId = -1;
	players.SetNum(playerNum);

	//��ʼ��ÿ����ҵ�����λ�ú���ת
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
	//�ڶ�Ӧλ�ú���ת����
	for (int i = 0; i < playerNum; ++i) {
		players[i] = GetWorld()->SpawnActor<AOriginCharacter>(OriginCharClass, startLocation[i], startRotation[i]);
		players[i]->name = FString(GInstance->playerName[i].c_str());
		players[i]->rank = GInstance->playerRank[i];
		players[i]->playerId = i;
	}
	//����Ȩ������ǰ���
	for (int i = 0; i < playerNum; ++i) {
		GetWorld()->GetFirstPlayerController()->Possess(players[i]);
		GetWorld()->GetFirstPlayerController()->UnPossess();
	}

	GetWorld()->GetFirstPlayerController()->Possess(players[myPlayerId]);
	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;

	//todo:����֡0��֪ͨudp��ַ
	SendFrame();


	//-----------------------------------------------
	//����Ϊ����
	
}

void AGameLevelScriptActor::Tick(float DeltaTime)
{
	if (Udpmanager) {
		RecvMsg();
	}
}

//������Ϣ�ĸ�ʽΪNextFrameOpts
void AGameLevelScriptActor::SendFrame()
{
	msg::NextFrameOpts A;
	//����֡��ΪsyncId+1
	A.set_frameid(syncId+1);
	A.set_playerid(myPlayerId);
	A.set_roomid(roomId);

	//�ռ���ǰ֡����ҵ��ƶ������ͳ���
	AOriginCharacter* myPlayer = players[GInstance->myPlayerId];
	msg::OptionEvent *moveOpts = A.add_opts();
	moveOpts->set_playerid(myPlayerId);
	moveOpts->set_opttype(msg::OptionType::MoveId);
	moveOpts->set_eastvalue(myPlayer->EastValue);
	moveOpts->set_northvalue(myPlayer->NorthValue);
	moveOpts->set_charrotattion(myPlayer->GetMeshRotation());

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

//ÿ֡������Ϣ���յ���Ϣ��ʽΪLogicFrame
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

//����֡LogicFrame
void AGameLevelScriptActor::HandleFrames(const std::string& message)
{
	msg::LogicFrame data;
	data.ParseFromString(message);

	//��frameid<=syncid����
	if (data.frameid() <= syncId) return;

	//todoͬ���Լ��ͻ�����һ֡�߼�����
	if (lastFrameOpts != nullptr) {
		SyncLastFrame(*lastFrameOpts);
	}

	//todo���ܴ�syncid+1��frameid-1�Ĳ���
	for (int i = 0; i < data.unsyncframes_size() - 1; ++i) {
		auto tmpFrame = data.unsyncframes(i);
		if (tmpFrame.frameid() >= syncId+1 && tmpFrame.frameid() < data.frameid()) {
			JumpFrame(data.unsyncframes(i));
		}
	}

	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("recv frame id %d syncId %d"), data.frameid(), syncId));
	syncId = data.frameid();


	//��ȡ���һ��������frameid��
	if (data.unsyncframes_size() > 0) {
		//����lastFrameOpts
		delete lastFrameOpts;
		lastFrameOpts = new class msg::FrameOpts(data.unsyncframes(data.unsyncframes_size() - 1));
		//�����֡����
		HandleFrameEvent(*lastFrameOpts);
	}

	//�����Լ���ǰ֡�Ĳ���
	SendFrame();
}

void AGameLevelScriptActor::SyncLastFrame(const class msg::FrameOpts& data)
{
	//������ҵ������������ͬ��

	//����ͬ��λ�ú���ת
	for (int i = 0; i < data.opts_size(); ++i) {
		msg::OptionEvent opt = data.opts(i);
		switch (opt.opttype()) {
		case msg::OptionType::MoveId:
			//�Խ�ɫ���ƶ�����ͬ��
			FVector EastDirection(1, 0, 0);
			FVector NorthDirection(0, -1, 0);
			FVector DownDirection(0, 0, -1);
			if (opt.playerid() < playerNum && players[opt.playerid()]) {
				AOriginCharacter* tmpPlayer = players[opt.playerid()];
				
				if (data.frameid() > 0) {
					//ͬ��λ��
					tmpPlayer->SetActorTransform(tmpPlayer->logicTransform);
					FVector MoveDir = EastDirection * logicDeltatime * tmpPlayer->MaxWalkSpeed * opt.eastvalue() + NorthDirection * logicDeltatime * tmpPlayer->MaxWalkSpeed * opt.northvalue();
					tmpPlayer->AddActorLocalOffset(MoveDir, true);
					tmpPlayer->logicTransform = tmpPlayer->GetTransform();
					//ͬ����ת
					tmpPlayer->GetMesh()->SetRelativeRotation(FRotator(0, opt.charrotattion(), 0));
				}
				else {
					tmpPlayer->logicTransform = tmpPlayer->GetTransform();
				}
				
			}
			break;
		}
	}
}

void AGameLevelScriptActor::HandleFrameEvent(const class msg::FrameOpts& data)
{
	for (auto i = 0; i < data.opts_size(); ++i) {
		msg::OptionEvent opt = data.opts(i);
		switch (opt.opttype()) {
		//���������ƶ�����
		case msg::OptionType::MoveId:
			FVector EastDirection(1, 0, 0);
			FVector NorthDirection(0, -1, 0);
			if (opt.playerid() < playerNum && players[opt.playerid()]) {
				AOriginCharacter* tmpPlayer = players[opt.playerid()];
				tmpPlayer->SyncEastValue = opt.eastvalue();
				tmpPlayer->SyncNorthValue = opt.northvalue();
				//����
				if (tmpPlayer->SyncEastValue != 0.0 || tmpPlayer->SyncNorthValue != 0.0) {
					tmpPlayer->curSpeed = tmpPlayer->MaxWalkSpeed;
				}
				else {
					tmpPlayer->curSpeed = 0.0;
				}
				tmpPlayer->curDirectionVec = EastDirection * tmpPlayer->SyncEastValue + NorthDirection * tmpPlayer->SyncNorthValue;
			}
			break;
		}
	}
}

void AGameLevelScriptActor::JumpFrame(const class msg::FrameOpts& data)
{
	//������ҵ������������ͬ��

	//����ͬ��λ�ú���ת
	for (int i = 0; i < data.opts_size(); ++i) {
		msg::OptionEvent opt = data.opts(i);
		switch (opt.opttype()) {
		case msg::OptionType::MoveId:
			//�Խ�ɫ���ƶ�����ͬ������֡����Ҫ��ת
			FVector EastDirection(1, 0, 0);
			FVector NorthDirection(0, -1, 0);
			FVector DownDirection(0, 0, -1);
			if (opt.playerid() < playerNum && players[opt.playerid()]) {
				AOriginCharacter* tmpPlayer = players[opt.playerid()];

				if (data.frameid() > 0) {
					tmpPlayer->SetActorTransform(tmpPlayer->logicTransform);
					FVector MoveDir = EastDirection * logicDeltatime * tmpPlayer->MaxWalkSpeed * opt.eastvalue() + NorthDirection * logicDeltatime * tmpPlayer->MaxWalkSpeed * opt.northvalue();
					tmpPlayer->AddActorLocalOffset(MoveDir, true);
					tmpPlayer->logicTransform = tmpPlayer->GetTransform();
					//ͬ����ת
					tmpPlayer->GetMesh()->SetRelativeRotation(FRotator(0, opt.charrotattion(), 0));
				}
				else {
					tmpPlayer->logicTransform = tmpPlayer->GetTransform();
				}
			}
			break;
		}
	}
}
