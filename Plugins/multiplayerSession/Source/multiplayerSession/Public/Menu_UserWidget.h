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

protected:
	virtual  bool Initialize() override;//为什么要使用Initialize
	
private:
	UPROPERTY(meta=(BindWidget))//并指定该属性应该与一个 UI 控件进行绑定。这样，在使用该属性时，
	//引擎会自动将其与相应的 UI 控件关联起来，方便你在代码中直接操作该控件。
	//前提是：控件的名称 蓝图和C++中的必须一一致
	class UButton* HostButton;

	UPROPERTY(meta=(BindWidget))
	 UButton* JoinButton;

	//当按钮点击时需要完成的逻辑

	UFUNCTION()
	void HostButtonClicked();

	UFUNCTION()
	void JoinButtonClicked();

	//菜单类中访问子系统的指针。
	class UMultiplayerSessionsSubsystem* MultiplayerSessionsSubsystem;
};
