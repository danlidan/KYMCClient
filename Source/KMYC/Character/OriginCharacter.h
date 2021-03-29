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

	//���
	UPROPERTY(EditDefaultsOnly)
	class UDecalComponent* CursorToWorld;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//����
	FString name;
	//����
	int32 rank;
	//һ����Ϸ�е�id
	int32 playerId;
	//�ƶ�����
	float EastValue; //���ڷ��͸����������ƶ�����
	float NorthValue;
	float MaxWalkSpeed = 600.0;
	float SyncEastValue; //ͬ��ʱ���ƶ�����
	float SyncNorthValue;
	//��ɫ���߼�λ��
	UPROPERTY()
	FTransform logicTransform;

	//��ɫ�ĵ�ǰ�ٶ�(���ڲ��Ŷ���)�͵�ǰ�ٶ�����
	UPROPERTY(BlueprintReadOnly)
	float curSpeed = 0.0;
	UPROPERTY(BlueprintReadOnly)
	FVector curDirectionVec = {0, 0, 0};


	//��ɫ�ƶ�
	void MoveEast(float);
	void MoveNorth(float);

	//��ȡ��Ҷ������ĳ�����ת��
	float GetMeshRotation();
};
