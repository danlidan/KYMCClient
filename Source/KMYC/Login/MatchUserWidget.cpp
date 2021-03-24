// Fill out your copyright notice in the Description page of Project Settings.


#include "MatchUserWidget.h"
#include "UMG/Public/Components/Button.h"
#include "UMG/Public/Components/TextBlock.h"
#include "Login_LevelScriptActor.h"

bool UMatchUserWidget::Initialize()
{
	Super::Initialize();

	//绑定1v1按钮
	Button1v1 = Cast<UButton>(GetWidgetFromName("Button1v1"));
	if (Button1v1) {
		FScriptDelegate sgbDelegate;
		sgbDelegate.BindUFunction(this, "onClickedButton1v1");
		Button1v1->OnReleased.Add(sgbDelegate);
	}

	//绑定2v2按钮
	Button2v2 = Cast<UButton>(GetWidgetFromName("Button2v2"));
	if (Button2v2) {
		FScriptDelegate sgbDelegate;
		sgbDelegate.BindUFunction(this, "onClickedButton2v2");
		Button2v2->OnReleased.Add(sgbDelegate);
	}

	//绑定取消匹配按钮
	ButtonCancel = Cast<UButton>(GetWidgetFromName("ButtonCancel"));
	if (ButtonCancel) {
		FScriptDelegate sgbDelegate;
		sgbDelegate.BindUFunction(this, "onClickedButtonCancel");
		ButtonCancel->OnReleased.Add(sgbDelegate);
	}

	//绑定文本框
	TextRank = Cast<UTextBlock>(GetWidgetFromName("TextRank"));
	TextMatching = Cast<UTextBlock>(GetWidgetFromName("TextMatching"));

	//隐藏匹配中ui
	RemoveMatchViewPort();

	return true;
}

void UMatchUserWidget::AddMatchViewPort()
{
	if (ButtonCancel) ButtonCancel->SetVisibility(ESlateVisibility::Visible);
	if (TextMatching) TextMatching->SetVisibility(ESlateVisibility::Visible);
}

void UMatchUserWidget::RemoveMatchViewPort()
{
	if (ButtonCancel) ButtonCancel->SetVisibility(ESlateVisibility::Hidden);
	if (TextMatching) TextMatching->SetVisibility(ESlateVisibility::Hidden);
}

void UMatchUserWidget::EnableMatchButton()
{
	if (Button1v1) Button1v1->SetIsEnabled(true);
	if (Button2v2) Button2v2->SetIsEnabled(true);
}

void UMatchUserWidget::DisableMatchButtion()
{
	if (Button1v1) Button1v1->SetIsEnabled(false);
	if (Button2v2) Button2v2->SetIsEnabled(false);
}

void UMatchUserWidget::onClickedButton1v1()
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("clicked1"));
	//TextRank->SetText(FText::FromString(FString::Printf(TEXT("clicked1"))));
	DisableMatchButtion();
	AddMatchViewPort();
	//0:1v1
	LVActor->SendMatchReq(0);
}


//todo
void UMatchUserWidget::onClickedButton2v2()
{
	DisableMatchButtion();
	AddMatchViewPort();
	//1:2v2
	LVActor->SendMatchReq(1);
}

void UMatchUserWidget::onClickedButtonCancel()
{
	LVActor->SendMatchCancelReq();
}
