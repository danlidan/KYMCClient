// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "GameLevelScriptActor.generated.h"

/**
 * 
 */
UCLASS()
class KMYC_API AGameLevelScriptActor : public ALevelScriptActor
{
	GENERATED_BODY()
public:
	void BeginPlay();

	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	class UKMYCInstance *GInstance;

	//用于处理udp
	UPROPERTY()
	class UUDPSocket *Udpmanager;

	UPROPERTY()
	TArray<FVector> startLocation; //初始出生点位置，下标为playerid

	UPROPERTY()
	TArray<FRotator> startRotation; //初始旋转，下标为playerid

	int32 playerNum; //玩家数
	int32 myPlayerId; //该玩家的id

	UPROPERTY()
	TArray<class AOriginCharacter*> players; //指向每个玩家

	//角色蓝图类型
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AOriginCharacter> OriginCharClass;

	//帧发送
	void SendFrame(const std::string& testInfo);
private:
	std::string Int32ToStr16(int32 val);

	int32 Str16ToInt32(std::string s);

	//每帧的消息接收
	void RecvMsg();

	//处理消息
	void HandleFrames(const std::string& message);
};
