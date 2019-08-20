// Fill out your copyright notice in the Description page of Project Settings.

#include "ABPlayerController.h"

void AABPlayerController::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	ABLOG_S(Warning);
}

void AABPlayerController::Possess(APawn*aPawn)
{
	ABLOG_S(Warning);
	Super::Possess(aPawn);
}


//컨트롤러로 오는 입력 잡아채서 좌우입력 안되도록 만들어 본 예제
//void AABPlayerController::SetupInputComponent()
//{
//	Super::SetupInputComponent();
//	InputComponent->BindAxis(TEXT("LeftRight"), this, &AABPlayerController::LeftRight);
//}
//
//void AABPlayerController::LeftRight(float NewAxisValue)
//{
//	// do nothing!
//}

void AABPlayerController::BeginPlay()
{
	Super::BeginPlay();

	FInputModeGameOnly InputMode;
	SetInputMode(InputMode);
}
