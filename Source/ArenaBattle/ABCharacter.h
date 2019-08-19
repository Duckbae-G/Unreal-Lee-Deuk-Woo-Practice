// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "GameFramework/Character.h"
#include "ABCharacter.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnAttackEndDelegate);

UCLASS()
class ARENABATTLE_API AABCharacter : public ACharacter
{
	GENERATED_BODY()

	public:
	// Sets default values for this character's properties
	AABCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//���۽��� ��� ����Լ� ����
	void SetControlMode(int32 ControlMode);

	//���۽��� ��� ������ ����

	enum class EControlMode
	{
		GTA,
		DIABLO,
		NPC
	};
	//���۽��� ��� �Լ� ����

	void SetControlMode(EControlMode NewControlMode);
	EControlMode CurrentControlMode = EControlMode::GTA;
	FVector DirectionToMove = FVector::ZeroVector;

	//�ε巴�� ���۽��� ��� �����ϱ� ���� ���� ����

	float ArmLengthTo = 0.0f;
	FRotator ArmRotationTo = FRotator::ZeroRotator;
	float ArmLengthSpeed = 0.0f;
	float ArmRotationSpeed = 0.0f;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// 
	virtual void PostInitializeComponents() override;
	// TakeDamage�Լ� �������̵��ϱ�
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamagaCauser) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void PossessedBy(AController* NewController) override;

	UPROPERTY(VisibleAnyWhere, Category = Weapon)
	USkeletalMeshComponent* Weapon;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	UCameraComponent* Camera;

	

	//�������� ���� �Լ� ���� ����
	bool CanSetWeapon();
	void SetWeapon(class AABWeapon* NewWeapon);

	UPROPERTY(VisibleAnywhere, Category = Weapon)
	class AABWeapon* CurrentWeapon;

	//Stat Data ���� Ŭ���� ����
	UPROPERTY(VisibleAnywhere, Category = Stat)
	class UABCharacterStatComponent* CharacterStat;

	// HPBar UI
	UPROPERTY(VisibleAnywhere, Category = UI)
	class UWidgetComponent* HPBarWidget;
	
	//Public���� ����. AIController������ ���� ��� ���� �� �ֵ��� �ϱ� ����.
	//���� �Լ� ����
	void Attack();
	FOnAttackEndDelegate OnAttackEnd;

private:

	//�����Ӱ� �þ���ȯ ���� �Լ� ����
	void UpDown(float NewAxisValue);
	void LeftRight(float NewAxisValue);
	void LookUp(float NewAxisValue);
	void Turn(float NewAxisValue);

	//������� ��ȯ�ϱ� ���� �Լ� forward-declare
	void ViewChange();

	
	
	//Attack �ִԸ�Ÿ�� �������� �ƴ��� üũ�ϴ� �Լ�, ��������Ʈ ����
	UFUNCTION()
	void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);

	//Attack ���۰� �� �Լ� ���� �����ϱ�
	void AttackStartComboState();
	void AttackEndComboState();
	void AttackCheck();
	

private:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	bool IsAttacking;

	//�޺����� ���� �����ϱ�

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	bool CanNextCombo;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	bool IsComboInputOn;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	int32 CurrentCombo;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	int32 MaxCombo;

	// Attack-Range Debug Drawing ���� ���� ����

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	float AttackRange;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	float AttackRadius;

	//�ִ��ν��Ͻ��� ��� ������ ���� �����ϱ�
	UPROPERTY()
	class UABAnimInstance* ABAnim;

	
};
