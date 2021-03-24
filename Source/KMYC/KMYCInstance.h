// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "KMYCInstance.generated.h"

/**
 * 
 */
UCLASS()
class KMYC_API UKMYCInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UKMYCInstance();

	UPROPERTY()
	class USocket *KMYCsocket;

	FString UserName;
	int32 UserRank;

	//游戏相关内容
	int32 playerNum; //游戏人数
	int32 myPlayerId; //该客户端玩家id
	std::vector<std::string> playerName;
	std::vector<int32> playerRank;
};
