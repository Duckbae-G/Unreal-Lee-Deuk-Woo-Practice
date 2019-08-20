// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "GameFramework/PlayerController.h"
#include "ABPlayerController.generated.h"

/**
*
*/
UCLASS()
class ARENABATTLE_API AABPlayerController : public APlayerController
{
	GENERATED_BODY()

	public:
	virtual void PostInitializeComponents() override;
	virtual void Possess(APawn* aPawn) override;

protected:
	//virtual void SetupInputComponent() override;
	virtual void BeginPlay() override;


	//좌우입력 하이잭 해보는 예제용. 입력은 보통 폰에서 구현하나, 엔진에서는 컨트롤러를 거쳐서 폰으로 간다.
	//private:
	//	void LeftRight(float NewAxisValue);
};
