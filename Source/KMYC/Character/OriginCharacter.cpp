// Fill out your copyright notice in the Description page of Project Settings.


#include "OriginCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/SceneComponent.h"
#include "Components/CapsuleComponent.h"
#include "Engine/EngineTypes.h"
#include "GameFramework/Actor.h"
#include "Kismet/KismetMathLibrary.h"

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

	//设置鼠标
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
	
	//初始逻辑位置同步
	logicTransform = GetTransform();
}

// Called every frame
void AOriginCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//更新鼠标贴图位置
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

	//监听移动,移速为600.0
	GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Red, GetTransform().ToString());
	GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Red, GetMesh()->GetRelativeRotation().ToString());

	FVector Direction1(1, 0, 0);
	AddActorLocalOffset(Direction1 * DeltaTime * SyncEastValue * MaxWalkSpeed, true);

	FVector Direction2(0, -1, 0);
	AddActorLocalOffset(Direction2 * DeltaTime * SyncNorthValue * MaxWalkSpeed, true);
}

// Called to bind functionality to input
void AOriginCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//移动绑定
	PlayerInputComponent->BindAxis("MoveEast", this, &AOriginCharacter::MoveEast);
	PlayerInputComponent->BindAxis("MoveNorth", this, &AOriginCharacter::MoveNorth);
}

void AOriginCharacter::MoveEast(float value)
{
	EastValue = value;
}

void AOriginCharacter::MoveNorth(float value)
{
	NorthValue = value;
}

float AOriginCharacter::GetMeshRotation()
{
	if (APlayerController* PC = Cast<APlayerController>(GetController())) {
		FHitResult TraceHitResult;
		PC->GetHitResultUnderCursor(ECC_Visibility, true, TraceHitResult);
		FRotator r = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), TraceHitResult.Location);

		return r.Yaw - 90.0;
	}

	return -90.0;
}

