// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "OriginCharacter.generated.h"

UCLASS()
class KMYC_API AOriginCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AOriginCharacter();
	AOriginCharacter(FString &n, int32 r, int32 id);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USpringArmComponent *SpringArm;

	UPROPERTY(EditAnywhere)
	class UCameraComponent *Camera;

	//鼠标
	UPROPERTY(EditDefaultsOnly)
	class UDecalComponent* CursorToWorld;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//名称
	FString name;
	//积分
	int32 rank;
	//一局游戏中的id
	int32 playerId;
	//移动参数
	float EastValue; //用于发送给服务器的移动参数
	float NorthValue;
	float MaxWalkSpeed = 600.0;
	float SyncEastValue; //同步时的移动参数
	float SyncNorthValue;
	//角色的逻辑位置
	UPROPERTY()
	FTransform logicTransform;

	//角色的当前速度(用于播放动画)和当前速度向量
	UPROPERTY(BlueprintReadOnly)
	float curSpeed = 0.0;
	UPROPERTY(BlueprintReadOnly)
	FVector curDirectionVec = {0, 0, 0};


	//角色移动
	void MoveEast(float);
	void MoveNorth(float);

	//获取玩家对于鼠标的朝向（旋转）
	float GetMeshRotation();
};
