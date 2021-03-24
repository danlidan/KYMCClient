// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTestCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AMyTestCharacter::AMyTestCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	//初始按键
	ForwardValue = RightValue = 0;
	
	
	//设置弹簧臂和摄像机
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetRelativeLocation(FVector(0, 0, 70.f));
	SpringArm->SetupAttachment(GetCapsuleComponent());
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	

	//测试数值
	testV = 1.0;
	frameid = 0;
}

// Called when the game starts or when spawned
void AMyTestCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyTestCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	

	//每帧根据按键情况移动
	FVector Direction1 = FRotationMatrix(GetCapsuleComponent()->GetComponentRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction1, ForwardValue);

	FVector Direction2 = FRotationMatrix(GetCapsuleComponent()->GetComponentRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction2, RightValue);
	

	//测试：每帧直接前进
	/*
	FTransform nextTrans = GetCapsuleComponent()->GetComponentTransform();
	nextTrans.AddToTranslation(FVector(2, 0, 0));
	SetActorTransform(nextTrans);
	
	
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("before " + nextTrans.ToString() + "after " + GetCapsuleComponent()->GetComponentTransform().ToString()));
	*/

	
	//FTransform nextTrans = GetCapsuleComponent()->GetComponentTransform();
	//AddActorLocalOffset(FVector(DeltaTime * 600, 0, 0), true);

	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("before " + nextTrans.ToString() + "after " + GetCapsuleComponent()->GetComponentTransform().ToString()));
	
	
}

// Called to bind functionality to input
void AMyTestCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	
	//绑定移动
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyTestCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyTestCharacter::MoveRight);
	

}


void AMyTestCharacter::MoveForward(float Value)
{
	//ForwardValue = Value;
}

void AMyTestCharacter::MoveRight(float Value)
{
	//RightValue = Value;
}

void AMyTestCharacter::receiveMove()
{
	//首先回到前一帧的逻辑位置
	
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("moving"));
	if (frameid > 0) {
		//0.05 : delat time, 600 : speed;

		SetActorTransform(logicTransform);

		AddActorLocalOffset(FVector(1, 0, 0) * 0.05 * 600.0, true);

		logicTransform = GetCapsuleComponent()->GetComponentTransform();
	}
	else {
		logicTransform = GetCapsuleComponent()->GetComponentTransform();
	}
	
	ForwardValue = 1.0;

	++frameid;
}

