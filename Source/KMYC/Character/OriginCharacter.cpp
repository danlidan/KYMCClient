// Fill out your copyright notice in the Description page of Project Settings.


#include "OriginCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"

// Sets default values
AOriginCharacter::AOriginCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetMesh()->SetRelativeLocation(FVector(0, 0, -90));
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));
	GetMesh()->SetRelativeScale3D(FVector(1.5, 1.5, 1.5));

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	// Don't want arm to rotate when character does
	SpringArm->SetUsingAbsoluteRotation(true);
	SpringArm->SetRelativeLocation(FVector(0, 955, 1580));
	SpringArm->SetRelativeRotation(FRotator(-60, -90, 0));

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	Camera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	//�������
	CursorToWorld = CreateDefaultSubobject<UDecalComponent>("CursorToWorld");
	CursorToWorld->SetupAttachment(RootComponent);
	CursorToWorld->DecalSize = FVector(16.0f, 32.0f, 32.0f);

}

AOriginCharacter::AOriginCharacter(FString &n, int32 r, int32 id): name(n), rank(r), playerId(id)
{

}

// Called when the game starts or when spawned
void AOriginCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOriginCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//���������ͼλ��
	if (CursorToWorld) {
		if (APlayerController* PC = Cast<APlayerController>(GetController())) {
			FHitResult TraceHitResult;
			PC->GetHitResultUnderCursor(ECC_Visibility, true, TraceHitResult);
			FVector CursorFV = TraceHitResult.ImpactNormal;
			FRotator CursorR = CursorFV.Rotation();
			CursorToWorld->SetWorldLocation(TraceHitResult.Location);
			CursorToWorld->SetWorldRotation(CursorR);
		}
	}
}

// Called to bind functionality to input
void AOriginCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//�ƶ���
	PlayerInputComponent->BindAxis("MoveEast", this, &AOriginCharacter::MoveEast);
	PlayerInputComponent->BindAxis("MoveNorth", this, &AOriginCharacter::MoveNorth);
}

void AOriginCharacter::MoveEast(float value)
{
	FVector Direction(1, 0, 0);
	AddMovementInput(Direction, value);
}

void AOriginCharacter::MoveNorth(float value)
{
	FVector Direction(0, -1, 0);
	AddMovementInput(Direction, value);
}
