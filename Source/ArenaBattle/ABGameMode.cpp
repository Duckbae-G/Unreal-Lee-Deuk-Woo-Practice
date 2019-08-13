// Fill out your copyright notice in the Description page of Project Settings.

#include "ABGameMode.h"
#include "ABCharacter.h"
#include "ABPlayerController.h"

AABGameMode::AABGameMode()
{
	DefaultPawnClass = AABCharacter::StaticClass(); // ��Ƽ�÷��� ����Ͽ� ���� �̸� �������� �ʰ� �׶��׶� üũ�ؼ� �����ϵ��� �ۼ�
	PlayerControllerClass = AABPlayerController::StaticClass();
	//�������Ʈ�� ���۵� ����ŷ �� �����ϴ� �ڵ�
	/*static ConstructorHelpers::FClassFinder<APawn> BP_PAWN_C(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter.ThirdPersonCharacter_C"));
	if (BP_PAWN_C.Succeeded())
	{
	DefaultPawnClass = BP_PAWN_C.Class;
	}*/
}

void AABGameMode::PostLogin(APlayerController * NewPlayer)
{
	//PostLogin�� �߻��Ǵ� �ϵ� �˱����� �α� �ڵ�
	ABLOG(Warning, TEXT("PostLogin Begin"));
	Super::PostLogin(NewPlayer);
	ABLOG(Warning, TEXT("PostLogin ENd"));
}

