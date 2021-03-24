// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "UObject/NoExportTypes.h"
#include "MyTestCharacter.generated.h"

UCLASS()
class KMYC_API AMyTestCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyTestCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	//监控是否按下前进
	UPROPERTY(BlueprintReadWrite)
	float ForwardValue;

	//监控是否按下向右
	UPROPERTY(BlueprintReadWrite)
	float RightValue;

	
	void MoveForward(float Value);
	void MoveRight(float Value);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USpringArmComponent *SpringArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UCameraComponent *Camera;

	//以下是测试代码
	int32 frameid = 0;
	float testV;
	void receiveMove();

	UPROPERTY(BlueprintReadOnly)
	FTransform logicTransform;
};
