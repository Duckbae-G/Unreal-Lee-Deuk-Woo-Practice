// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "Animation/AnimInstance.h"
#include "ABAnimInstance.generated.h"

//AttackMontage ��Ƽ���� üũ�� ��������Ʈ ����
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

	//���� �ִ��ν��Ͻ����� �� ���� ������ forward declare
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	//���� �ִԸ�Ÿ�� ���� ������
	void PlayAttackMontage();
	void JumpToAttackMontageSection(int32 NewSection);

	//��������Ʈ �̸� ����
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
	//���� ���� �ӵ� ��������
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	float CurrentPawnSpeed;

	//���߻������� ��������
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	bool IsInAir;

	//Attack �ִԸ�Ÿ�� ������Ƽ �����
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	UAnimMontage* AttackMontage;

	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	bool IsDead;
};
