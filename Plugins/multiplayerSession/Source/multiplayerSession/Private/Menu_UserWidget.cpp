// Fill out your copyright notice in the Description page of Project Settings.


#include "Menu_UserWidget.h"

void UMenu_UserWidget::MenuSetup()
{
	AddToViewport();//将这个UI添加到视口
	SetVisibility(ESlateVisibility::Visible);//设置可见
	bIsFocusable=true;//让这个 UI 元素能够接收焦点，从而能够与用户的输入进行交互，比如接收键盘输入或鼠标点击。

	//设置输入模式
	UWorld* world=GetWorld();
	if(world)
	{
		APlayerController* PlayerController=world->GetFirstPlayerController();//获取这个世界中第一个玩家的控制器
		if(PlayerController)
		{
			FInputModeUIOnly InputModeData;//用于定义 UI 输入模式的结构体对象
			InputModeData.SetWidgetToFocus(TakeWidget());//TakeWidget() 函数用于获取当前 UI 元素的 Widget，并将其设置为输入模式的焦点，以便该 UI 元素能够接收用户的输入。
			InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);//允许鼠标在视口中自由移动。
			
			PlayerController->SetInputMode(InputModeData);
			PlayerController->SetShowMouseCursor(true);//显示鼠标光针
		}
	}
}
                                                                                                