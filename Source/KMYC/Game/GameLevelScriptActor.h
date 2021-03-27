// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "../Msg/game.pb.h"
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
	int32 roomId; //�����

	UPROPERTY()
	TArray<class AOriginCharacter*> players; //ָ��ÿ�����

	//��ɫ��ͼ����
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AOriginCharacter> OriginCharClass;

	//֡����
	void SendFrame();
private:
	int32 syncId; //��ǰͬ������֡��
	float logicDeltatime = 0.066; //�߼�֡���

	class msg::FrameOpts *lastFrameOpts; //�ͻ��˽��յ�����һ֡���߼�����

	std::string Int32ToStr16(int32 val);

	int32 Str16ToInt32(const std::string& s);

	//ÿ֡����Ϣ����
	void RecvMsg();

	//������Ϣ
	void HandleFrames(const std::string& message);

	//������һ֡����
	void SyncLastFrame(const class msg::FrameOpts& data);

	//����ǰ���һ֡����
	void HandleFrameEvent(const class msg::FrameOpts& data);

	//��֡�����֡
	void JumpFrame(const class msg::FrameOpts& data);
};
