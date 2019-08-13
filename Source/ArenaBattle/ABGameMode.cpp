// Fill out your copyright notice in the Description page of Project Settings.

#include "ABGameMode.h"
#include "ABCharacter.h"
#include "ABPlayerController.h"

AABGameMode::AABGameMode()
{
	DefaultPawnClass = AABCharacter::StaticClass(); // 멀티플레이 고려하여 폰을 미리 만들어두지 않고 그때그때 체크해서 생성하도록 작성
	PlayerControllerClass = AABPlayerController::StaticClass();
	//블루프린트로 제작된 마네킹 폰 지정하는 코드
	/*static ConstructorHelpers::FClassFinder<APawn> BP_PAWN_C(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter.ThirdPersonCharacter_C"));
	if (BP_PAWN_C.Succeeded())
	{
	DefaultPawnClass = BP_PAWN_C.Class;
	}*/
}

void AABGameMode::PostLogin(APlayerController * NewPlayer)
{
	//PostLogin때 발생되는 일들 알기위한 로그 코드
	ABLOG(Warning, TEXT("PostLogin Begin"));
	Super::PostLogin(NewPlayer);
	ABLOG(Warning, TEXT("PostLogin ENd"));
}

