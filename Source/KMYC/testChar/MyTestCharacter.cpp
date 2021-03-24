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

	
	//��ʼ����
	ForwardValue = RightValue = 0;
	
	
	//���õ��ɱۺ������
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetRelativeLocation(FVector(0, 0, 70.f));
	SpringArm->SetupAttachment(GetCapsuleComponent());
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	

	//������ֵ
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
	

	//ÿ֡���ݰ�������ƶ�
	FVector Direction1 = FRotationMatrix(GetCapsuleComponent()->GetComponentRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction1, ForwardValue);

	FVector Direction2 = FRotationMatrix(GetCapsuleComponent()->GetComponentRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction2, RightValue);
	

	//���ԣ�ÿֱ֡��ǰ��
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

	
	//���ƶ�
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
	//���Ȼص�ǰһ֡���߼�λ��
	
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

