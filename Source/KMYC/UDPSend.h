// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UDPSend.generated.h"

UCLASS()
class KMYC_API AUDPSend : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUDPSend();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool IsUDP;

	UFUNCTION(BlueprintCallable, Category = "UDP")
	bool RamaUDPSender_SendString(FString ToSend);

	//发送消息用
	void SendMsg(std::string msg);

	TSharedPtr<FInternetAddr> RemoteAddr;
	FSocket* SenderSocket;

	UFUNCTION(BlueprintCallable, Category = "UDP")
	bool StartUDPSender(const FString& YourChosenSocketName, const FString& TheIP, const int32 ThePort, bool UDP);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UDP")
	bool ShowOnScreenDebugMessages;


	//ScreenMsg  
	FORCEINLINE void ScreenMsg(const FString& Msg) {
		if (!ShowOnScreenDebugMessages) return;
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, *Msg);
	}
	
	FORCEINLINE void ScreenMsg(const FString& Msg, const float Value)
	{
		if (!ShowOnScreenDebugMessages) return;
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("%s %f"), *Msg, Value));
	}

	FORCEINLINE void ScreenMsg(const FString& Msg, const FString& Msg2)
	{
		if (!ShowOnScreenDebugMessages) return;
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("%s %s"), *Msg, *Msg2));
	}

	/** Called whenever this actor is being removed from a level */
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
