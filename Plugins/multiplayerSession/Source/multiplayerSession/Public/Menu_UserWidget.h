// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Menu_UserWidget.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERSESSION_API UMenu_UserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void MenuSetup();
};
