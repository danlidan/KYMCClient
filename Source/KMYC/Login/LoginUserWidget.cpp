// Fill out your copyright notice in the Description page of Project Settings.


#include "LoginUserWidget.h"
#include "Login_LevelScriptActor.h"
#include "UMG/Public/Components/Button.h"
#include "UMG/Public/Components/EditableText.h"

bool ULoginUserWidget::Initialize()
{
	Super::Initialize();

	//��ǰ��ע�ᰴť
	ButtonGoRegister = Cast<UButton>(GetWidgetFromName("ButtonGoRegister"));
	if (ButtonGoRegister) {
		FScriptDelegate sgbDelegate;
		sgbDelegate.BindUFunction(this, "onClickedGoRegister");
		ButtonGoRegister->OnReleased.Add(sgbDelegate);
	}

	//�󶨵�¼��ť
	ButtonLogin = Cast<UButton>(GetWidgetFromName("ButtonLogin"));
	if (ButtonLogin) {
		FScriptDelegate sgbDelegate;
		sgbDelegate.BindUFunction(this, "onClickedLogin");
		ButtonLogin->OnReleased.Add(sgbDelegate);
	}

	//���ı���
	TextNameLogin = Cast<UEditableText>(GetWidgetFromName("TextNameLogin"));
	TextPassLogin = Cast<UEditableText>(GetWidgetFromName("TextPassLogin"));

	return true;
}

void ULoginUserWidget::onClickedGoRegister()
{
	LVActor->Login2Register();
}

void ULoginUserWidget::onClickedLogin()
{
	std::string name = TCHAR_TO_UTF8(*(TextNameLogin->GetText().ToString()));
	std::string pass = TCHAR_TO_UTF8(*(TextPassLogin->GetText().ToString()));

	if (name.length() > 0 && pass.length() > 3) {
		LVActor->SendLoginReq(name, pass);
	}
}
