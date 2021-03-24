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

	//���ڴ���udp
	UPROPERTY()
	class UUDPSocket *Udpmanager;

	UPROPERTY()
	TArray<FVector> startLocation; //��ʼ������λ�ã��±�Ϊplayerid

	UPROPERTY()
	TArray<FRotator> startRotation; //��ʼ��ת���±�Ϊplayerid

	int32 playerNum; //�����
	int32 myPlayerId; //����ҵ�id

	UPROPERTY()
	TArray<class AOriginCharacter*> players; //ָ��ÿ�����

	//��ɫ��ͼ����
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AOriginCharacter> OriginCharClass;

	//֡����
	void SendFrame(const std::string& testInfo);
private:
	std::string Int32ToStr16(int32 val);

	int32 Str16ToInt32(std::string s);

	//ÿ֡����Ϣ����
	void RecvMsg();

	//������Ϣ
	void HandleFrames(const std::string& message);
};
