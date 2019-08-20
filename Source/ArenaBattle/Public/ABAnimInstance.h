// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "Animation/AnimInstance.h"
#include "ABAnimInstance.generated.h"

//AttackMontage 노티파이 체크용 델리게이트 생성
DECLARE_MULTICAST_DELEGATE(FOnNextAttackCheckDelegate);
DECLARE_MULTICAST_DELEGATE(FOnAttackHitCheckDelegate);

/**
*
*/
UCLASS()
class ARENABATTLE_API UABAnimInstance : public UAnimInstance
{
	GENERATED_BODY()


public:
	UABAnimInstance();

	//현재 애님인스턴스에서 폰 정보 얻어오기 forward declare
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	//공격 애님몽타주 정보 얻어오기
	void PlayAttackMontage();
	void JumpToAttackMontageSection(int32 NewSection);

	//델리케이트 이름 생성
	FOnNextAttackCheckDelegate OnNextAttackCheck;
	FOnAttackHitCheckDelegate OnAttackHitCheck;

	void SetDeadAnim() { IsDead = true; }

private:
	UFUNCTION()
	void AnimNotify_AttackHitCheck();

	UFUNCTION()
	void AnimNotify_NextAttackCheck();

	FName GetAttackMontageSectionName(int32 Section);

private:
	//폰의 현재 속도 가져오기
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	float CurrentPawnSpeed;

	//공중상태인지 가져오기
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	bool IsInAir;

	//Attack 애님몽타주 프로퍼티 만들기
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	UAnimMontage* AttackMontage;

	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	bool IsDead;
};
