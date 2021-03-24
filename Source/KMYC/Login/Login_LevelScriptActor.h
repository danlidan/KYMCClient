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

	//登录菜单的控件类,c++类型
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class ULoginUserWidget> LoginUICLass;

	//登录控件实例
	UPROPERTY(VisibleAnywhere)
	class ULoginUserWidget *LoginUI;

	//注册菜单的控件类,c++类型
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class URegisterUserWidget> RegisterUICLass;

	//注册控件实例
	UPROPERTY(VisibleAnywhere)
	class URegisterUserWidget *RegisterUI;

	//匹配界面
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<class UMatchUserWidget> MatchUICLass;

	//匹配界面实例
	UPROPERTY(VisibleAnywhere)
	class UMatchUserWidget *MatchUI;

	//登录->注册
	void Login2Register();
	//注册->登录
	void Register2Login();

	//由蓝图实现，登陆成功后切换视角
	UFUNCTION(BlueprintImplementableEvent)
	void ChangeCameraToReady();

	//由蓝图实现，匹配成功后切换关卡
	UFUNCTION(BlueprintImplementableEvent)
	void ChangeToGameScript();

	//协议发送
	void SendRegisterReq(std::string name, std::string pass);
	void SendLoginReq(std::string name, std::string pass);
	void SendMatchReq(int32 type);
	void SendMatchCancelReq();
private:
	//每帧调用，获取服务器消息
	void RecvMsg();

	UPROPERTY()
	class UKMYCInstance *GInstance;


	//协议接收
	void HandleRegisterRsp(std::string msg);
	void HandleLoginRsp(std::string msg);
	void HandleMatchRsp(std::string msg);
	void HandleMatchCancelRsp(std::string msg);
};
