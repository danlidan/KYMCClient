// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RegisterUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class KMYC_API URegisterUserWidget : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(meta = (BindWidget))
	class UButton* ButtonGoLogin;

	UPROPERTY(meta = (BindWidget))
	class UButton* ButtonRegister;

	UPROPERTY(meta = (BindWidget))
	class UEditableText* TextNameRegister;

	UPROPERTY(meta = (BindWidget))
	class UEditableText* TextPassRegister;

	UPROPERTY(meta = (BindWidget))
	class UEditableText* TextPass2Register;

public:
	bool Initialize();

	class ALogin_LevelScriptActor* LVActor;

	UFUNCTION()
	void onClickedGoLogin();

	UFUNCTION()
	void onClickedRegister();
};
