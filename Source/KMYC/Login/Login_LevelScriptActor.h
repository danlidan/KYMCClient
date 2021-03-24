// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "Login_LevelScriptActor.generated.h"

/**
 * 
 */
UCLASS()
class KMYC_API ALogin_LevelScriptActor : public ALevelScriptActor
{
	GENERATED_BODY()
public:
	void BeginPlay();

	virtual void Tick(float DeltaTime) override;

	//��¼�˵��Ŀؼ���,c++����
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class ULoginUserWidget> LoginUICLass;

	//��¼�ؼ�ʵ��
	UPROPERTY(VisibleAnywhere)
	class ULoginUserWidget *LoginUI;

	//ע��˵��Ŀؼ���,c++����
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class URegisterUserWidget> RegisterUICLass;

	//ע��ؼ�ʵ��
	UPROPERTY(VisibleAnywhere)
	class URegisterUserWidget *RegisterUI;

	//ƥ�����
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<class UMatchUserWidget> MatchUICLass;

	//ƥ�����ʵ��
	UPROPERTY(VisibleAnywhere)
	class UMatchUserWidget *MatchUI;

	//��¼->ע��
	void Login2Register();
	//ע��->��¼
	void Register2Login();

	//����ͼʵ�֣���½�ɹ����л��ӽ�
	UFUNCTION(BlueprintImplementableEvent)
	void ChangeCameraToReady();

	//����ͼʵ�֣�ƥ��ɹ����л��ؿ�
	UFUNCTION(BlueprintImplementableEvent)
	void ChangeToGameScript();

	//Э�鷢��
	void SendRegisterReq(std::string name, std::string pass);
	void SendLoginReq(std::string name, std::string pass);
	void SendMatchReq(int32 type);
	void SendMatchCancelReq();
private:
	//ÿ֡���ã���ȡ��������Ϣ
	void RecvMsg();

	UPROPERTY()
	class UKMYCInstance *GInstance;


	//Э�����
	void HandleRegisterRsp(std::string msg);
	void HandleLoginRsp(std::string msg);
	void HandleMatchRsp(std::string msg);
	void HandleMatchCancelRsp(std::string msg);
};
