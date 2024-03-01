// Fill out your copyright notice in the Description page of Project Settings.


#include "Menu_UserWidget.h"

#include "MultiplayerSessionsSubsystem.h"
#include "Components/Button.h"

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

	//游戏实例（Game Instance）创建完成之后，会自动创建一个游戏实例子系统（Game Instance Subsystem）
	//所有可以从GameInstance中访问到GameInstanceSubsystem
	UGameInstance* GameInstance=GetGameInstance();
	if(GameInstance)
	{
		MultiplayerSessionsSubsystem= GameInstance->GetSubsystem<UMultiplayerSessionsSubsystem>();
	}
}

bool UMenu_UserWidget::Initialize()
{
	if(!Super::Initialize())
	{
		return false;
	}
	if(HostButton)
	{
		HostButton->OnClicked.AddDynamic(this,&ThisClass::HostButtonClicked);
	}
	if(JoinButton)
	{
		JoinButton->OnClicked.AddDynamic(this,&ThisClass::JoinButtonClicked);
	}
	return true;
}

void UMenu_UserWidget::HostButtonClicked()
{
	//屏幕调试信息
	if(GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			15.f,
			FColor::Yellow,
			FString((TEXT("创建按钮点击了，正在试图创建会话")))
			);
	}

	if(MultiplayerSessionsSubsystem)
	{
		MultiplayerSessionsSubsystem->CreateSession(4,FString("FreeForAll"));//创建一个名为“FreeForAll”的容纳四个人的会话
	}
}

void UMenu_UserWidget::JoinButtonClicked()
{
	if(GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			15.f,
			FColor::Yellow,
			FString((TEXT("加入按钮点击了，正在试图加入会话")))
			);
	}
}
                                                                                                