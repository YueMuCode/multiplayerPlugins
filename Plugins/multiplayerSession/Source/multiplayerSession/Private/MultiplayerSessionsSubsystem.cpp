// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiplayerSessionsSubsystem.h"
#include "OnlineSubsystem.h"

UMultiplayerSessionsSubsystem::UMultiplayerSessionsSubsystem()
{
	//Get() 是一个静态函数，它返回当前正在使用的在线子系统的实例，如果没有在线子系统可用，则返回空指针。
	IOnlineSubsystem* Subsystem=IOnlineSubsystem::Get();
	if(Subsystem)
	{
		// 在在线子系统可用时，这行代码获取在线会话接口的实例，并将其分配给 SessionInterface 变量。
		// 在线会话接口 (IOnlineSession) 提供了管理多人游戏会话的功能，如创建、查找、加入和销毁游戏会话等
		SessionInterface=Subsystem->GetSessionInterface();
	}
}
