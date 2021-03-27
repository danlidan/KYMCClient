// Fill out your copyright notice in the Description page of Project Settings.


#include "Login_LevelScriptActor.h"
#include "../KMYCInstance.h"
#include "../Socket.h"
#include "../Msg/log.pb.h"
#include "../Msg/protoId.pb.h"
#include "LoginUserWidget.h"
#include "RegisterUserWidget.h"
#include "MatchUserWidget.h"
#include "UMG/Public/Components/TextBlock.h"
#include <vector>

//proto消息格式： len 2Byte | id 2Byte | protobuf message
//len 为 id + message的长度，不包括len本身
//len & id 均为大端编码， 根据id区分消息类型

void ALogin_LevelScriptActor::BeginPlay()
{

	PrimaryActorTick.bCanEverTick = true;

	Super::BeginPlay();

	//显示鼠标
	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;

	//初始化登录UMG并显示
	LoginUI = CreateWidget<ULoginUserWidget>(GetWorld(), LoginUICLass);
	LoginUI->LVActor = this;
	LoginUI->AddToViewport();

	//初始化注册UMG不显示
	RegisterUI = CreateWidget<URegisterUserWidget>(GetWorld(), RegisterUICLass);
	RegisterUI->LVActor = this;
	
	//初始化匹配UMG不显示
	MatchUI = CreateWidget<UMatchUserWidget>(GetWorld(), MatchUICLass);
	MatchUI->LVActor = this;


	//初始化tcp连接
	GInstance = Cast<UKMYCInstance>(GetGameInstance());

	
	if (!GInstance->KMYCsocket) {
		GInstance->KMYCsocket = NewObject<USocket>();
	}

	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello World, this is scirpter!"));
}

void ALogin_LevelScriptActor::Tick(float DeltaTime)
{
	
	//获取服务器消息
	if (GInstance->KMYCsocket) {
		RecvMsg();
	}
	
}

void ALogin_LevelScriptActor::RecvMsg()
{
	std::string recvData;
	GInstance->KMYCsocket->Recv(recvData);

	int32 msglen = recvData.length();
	int32 curlen = 0;
	while (curlen < msglen) {
		int32 len = GInstance->KMYCsocket->Str16ToInt32(recvData.substr(curlen, 2));
		int32 protoId = GInstance->KMYCsocket->Str16ToInt32(recvData.substr(curlen + 2, 2));
		switch (protoId) {
		case msg::ProtoId::RegisterRspId:
			HandleRegisterRsp(recvData.substr(curlen + 4, len - 2));
			break;
		case msg::ProtoId::LoginRspId:
			HandleLoginRsp(recvData.substr(curlen + 4, len - 2));
			break;
		case msg::ProtoId::MatchCancelRspId:
			HandleMatchCancelRsp(recvData.substr(curlen + 4, len - 2));
			break;
		case msg::ProtoId::MatchRspId:
			HandleMatchRsp(recvData.substr(curlen + 4, len - 2));
			break;
		default:
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("unregistered protoid %d"), protoId));
		}

		curlen += 2 + len;
	}
}

void ALogin_LevelScriptActor::Login2Register()
{
	LoginUI->RemoveFromViewport();
	RegisterUI->AddToViewport();
}

void ALogin_LevelScriptActor::Register2Login()
{
	RegisterUI->RemoveFromViewport();
	LoginUI->AddToViewport();
}

void ALogin_LevelScriptActor::SendRegisterReq(std::string name, std::string pass)
{
	msg::RegisterReq A;
	A.set_name(name);
	A.set_pass(pass);
	std::string a = A.SerializeAsString();
	GInstance->KMYCsocket->Send(a, msg::ProtoId::RegisterReqId);
}

void ALogin_LevelScriptActor::SendLoginReq(std::string name, std::string pass)
{
	msg::LoginReq A;
	A.set_name(name);
	A.set_pass(pass);
	std::string a = A.SerializeAsString();
	GInstance->KMYCsocket->Send(a, msg::ProtoId::LoginReqId);
}

void ALogin_LevelScriptActor::SendMatchReq(int32 type)
{
	msg::MatchReq A;
	A.set_type(type);
	std::string a = A.SerializeAsString();
	GInstance->KMYCsocket->Send(a, msg::ProtoId::MatchReqId);
}

void ALogin_LevelScriptActor::SendMatchCancelReq()
{
	msg::MatchCancelReq A;
	std::string a = A.SerializeAsString();
	GInstance->KMYCsocket->Send(a, msg::ProtoId::MatchCancelReqId);
}

void ALogin_LevelScriptActor::HandleRegisterRsp(std::string message)
{
	msg::RegisterRsp data;
	data.ParseFromString(message);
	if (data.success()) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("successfully registered！")));
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("register failed！")));
	}
}

void ALogin_LevelScriptActor::HandleLoginRsp(std::string message)
{
	msg::LoginRsp data;
	data.ParseFromString(message);
	if (data.success()) {
		//登录成功，todo
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("successfully logged in！")));
		//修改视角
		ChangeCameraToReady();
		LoginUI->RemoveFromViewport();
		//更改instance中的全局变量
		GInstance->UserName = FString(data.name().c_str());
		GInstance->UserRank = data.rank();
		//显示matchui
		MatchUI->AddToViewport();
		MatchUI->TextRank->SetText(FText::FromString(GInstance->UserName + FString::Printf(TEXT("'s Rank : %d"), data.rank())));
	}
	else {
		//登录失败
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("log in failed！")));
	}
}

void ALogin_LevelScriptActor::HandleMatchRsp(std::string message)
{
	msg::MatchRsp data;
	data.ParseFromString(message);

	//初始化gameInstance中的内容
	GInstance->playerNum = data.playernum();
	GInstance->myPlayerId = data.myplayerid();
	GInstance->roomId = data.roomid();
	GInstance->playerName.clear();
	GInstance->playerName = std::vector<std::string>(GInstance->playerNum);
	GInstance->playerRank.clear();
	GInstance->playerRank = std::vector<int32>(GInstance->playerNum);

	for (int i = 0; i < GInstance->playerNum; ++i) {
		GInstance->playerName[i] = data.players(i).name();
		GInstance->playerRank[i] = data.players(i).rank();
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString(GInstance->playerName[i].c_str()) + FString::Printf(TEXT(" %d begin game"), GInstance->playerRank[i]));
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("roomid %d"), GInstance->roomId));
	//切换到游戏
	ChangeToGameScript();
}

void ALogin_LevelScriptActor::HandleMatchCancelRsp(std::string message)
{
	msg::MatchCancelRsp data;
	data.ParseFromString(message);
	if (data.success()) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Match cancelled!")));
		//修改界面
		MatchUI->RemoveMatchViewPort();
		MatchUI->EnableMatchButton();
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Match cancell failed!")));
	}
}
