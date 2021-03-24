// Fill out your copyright notice in the Description page of Project Settings.


#include "RegisterUserWidget.h"
#include "Login_LevelScriptActor.h"
#include "UMG/Public/Components/Button.h"
#include "UMG/Public/Components/EditableText.h"

bool URegisterUserWidget::Initialize()
{
	Super::Initialize();

	//绑定前往登录按钮
	ButtonGoLogin = Cast<UButton>(GetWidgetFromName("ButtonGoLogin"));
	if (ButtonGoLogin) {
		FScriptDelegate sgbDelegate;
		sgbDelegate.BindUFunction(this, "onClickedGoLogin");
		ButtonGoLogin->OnReleased.Add(sgbDelegate);
	}

	//绑定注册按钮
	ButtonRegister = Cast<UButton>(GetWidgetFromName("ButtonRegister"));
	if (ButtonRegister) {
		FScriptDelegate sgbDelegate;
		sgbDelegate.BindUFunction(this, "onClickedRegister");
		ButtonRegister->OnReleased.Add(sgbDelegate);
	}

	//绑定文本框
	TextNameRegister = Cast<UEditableText>(GetWidgetFromName("TextNameRegister"));
	TextPassRegister = Cast<UEditableText>(GetWidgetFromName("TextPassRegister"));
	TextPass2Register = Cast<UEditableText>(GetWidgetFromName("TextPass2Register"));

	return true;
}

void URegisterUserWidget::onClickedGoLogin()
{
	LVActor->Register2Login();
}

void URegisterUserWidget::onClickedRegister()
{
	/*
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TextNameRegister->GetText().ToString());
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TextPassRegister->GetText().ToString());
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TextPass2Register->GetText().ToString());
	*/

	std::string name = TCHAR_TO_UTF8(*(TextNameRegister->GetText().ToString()));
	std::string pass = TCHAR_TO_UTF8(*(TextPassRegister->GetText().ToString()));
	std::string pass2 = TCHAR_TO_UTF8(*(TextPass2Register->GetText().ToString()));
	if (name.length() > 0 && pass.length() > 3 && pass == pass2) {
		LVActor->SendRegisterReq(name, pass);
	}
}
