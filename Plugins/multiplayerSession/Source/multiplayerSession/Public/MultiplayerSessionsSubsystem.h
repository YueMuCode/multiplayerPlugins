// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"//?

#include "MultiplayerSessionsSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERSESSION_API UMultiplayerSessionsSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UMultiplayerSessionsSubsystem();

	//当要通过菜单创建一个会话的时候，将会调用下面的函数
	void CreateSession(int32 NumPublicConnections,FString MatchType);//创建一个会话，可参加人数+匹配条件
	void FindSessions(int32 MaxSearchResults);//搜索已经存在的会话.存在的会话数目
	void JoinSession(const FOnlineSessionSearchResult& SessionResult);//加入会话，返回的搜索到的会话结果
	void DestroySession();//销毁会话
	void StartSession();//启动会话？
	
protected:
	//内部回调函数
	void OnCreateSessionComplete(FName SessionName,bool bWasSuccessful);
	void OnFindSessionsComplete(bool bWasSuccessful);
	void OnJoinSessionComplete(FName SessionName,EOnJoinSessionCompleteResult::Type Result);
	void OnDestroySessionComplete(FName	SessionName,bool bWasSuccessful);
	void OnStartSessionComplete(FName SessionName,bool bWasSuccessful);

private:
	IOnlineSessionPtr SessionInterface;//IOnlineSessionPtr智能指针
	
	//委托列表，将要绑定对应的回调函数给这些委托

	FOnCreateSessionCompleteDelegate CreateSessionCompleteDelegate;
	FOnFindSessionsCompleteDelegate FindSessionCompleteDelegate;
	FOnJoinSessionCompleteDelegate JoinSessionCompleteDelegate;
	FOnDestroySessionCompleteDelegate DestroySessionCompleteDelegate;
	FOnStartSessionCompleteDelegate StartSessionCompleteDelegate;

	//添加对应的委托句柄，作用相当于存储委托的变量
	FDelegateHandle CreateSessionCompleteDelegateHandle;
	FDelegateHandle FindSessionCompleteDelegateHandle;
	FDelegateHandle JoinSessionCompleteDelegateHandle;
	FDelegateHandle DestroySessionCompleteDelegateHandle;
	FDelegateHandle StartSessionCompleteDelegateHandle;
};
