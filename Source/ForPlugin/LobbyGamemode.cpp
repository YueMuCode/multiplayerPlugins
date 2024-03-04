// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGamemode.h"

#include "GameFramework/GameStateBase.h"
#include "GameFramework/PlayerState.h"

void ALobbyGamemode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
	if(GameState)
	{
		int NumberOfPlayers=GameState.Get()->PlayerArray.Num();
		if(GEngine)
		{
			GEngine->AddOnScreenDebugMessage(1,60.0f,FColor::Yellow,FString::Printf(TEXT("Players in game:%d"),NumberOfPlayers));
		}
		
		APlayerState* PlayerState=NewPlayer->GetPlayerState<APlayerState>();
		if(ensure(PlayerState))
		{
			FString PlayerName=PlayerState->GetPlayerName();
			if(GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1,60.0f,FColor::Cyan,FString::Printf(TEXT("%s has joined the game"),*PlayerName));
			}
		}
		
	}
}

void ALobbyGamemode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);

	APlayerState* PlayerState=Exiting->GetPlayerState<APlayerState>();
	if(ensure(PlayerState))
	{
		int NumberOfPlayers=GameState.Get()->PlayerArray.Num();
		if(GEngine)
		{
			GEngine->AddOnScreenDebugMessage(1,60.0f,FColor::Yellow,FString::Printf(TEXT("Players in game:%d"),NumberOfPlayers-1));
		}
		
		FString PlayerName=PlayerState->GetPlayerName();
		if(GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1,60.0f,FColor::Cyan,FString::Printf(TEXT("%s has exited the game"),*PlayerName));
		}
	}
	
}

