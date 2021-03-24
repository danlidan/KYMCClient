// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LoginUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class KMYC_API ULoginUserWidget : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(meta = (BindWidget))
	class UButton* ButtonGoRegister;

	UPROPERTY(meta = (BindWidget))
	class UButton* ButtonLogin;

	UPROPERTY(meta = (BindWidget))
	class UEditableText* TextNameLogin;

	UPROPERTY(meta = (BindWidget))
	class UEditableText* TextPassLogin;
	
public:
	bool Initialize();

	class ALogin_LevelScriptActor* LVActor;

	UFUNCTION()
	void onClickedGoRegister();

	UFUNCTION()
	void onClickedLogin();
};
