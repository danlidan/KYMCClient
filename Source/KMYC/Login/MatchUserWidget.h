// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MatchUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class KMYC_API UMatchUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(meta = (BindWidget))
	class UButton* Button1v1;

	UPROPERTY(meta = (BindWidget))
	class UButton* Button2v2;

	UPROPERTY(meta = (BindWidget))
	class UButton* ButtonCancel;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TextRank;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TextMatching;

	class ALogin_LevelScriptActor* LVActor;

	bool Initialize();

	//显示和隐藏匹配中ui
	void AddMatchViewPort();
	void RemoveMatchViewPort();
	
	//启用和弃用匹配按钮
	void EnableMatchButton();
	void DisableMatchButtion();

	UFUNCTION()
	void onClickedButton1v1();

	UFUNCTION()
	void onClickedButton2v2();

	UFUNCTION()
	void onClickedButtonCancel();
};
