// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "ABPawn.generated.h"

UCLASS()
class ARENABATTLE_API AABPawn : public APawn
{
	GENERATED_BODY()

	public:
	// Sets default values for this pawn's properties
	AABPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void PostInitializeComponents() override;
	virtual void PossessedBy(AController * NewController) override;


	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	//사용할 컴포넌트 선언
	UPROPERTY(VisibleAnywhere, Category = Collision)
	UCapsuleComponent* Capsule;

	UPROPERTY(VisibleAnywhere, Category = Visual)
	USkeletalMeshComponent * Mesh;

	UPROPERTY(VisibleAnywhere, Category = Movement)
	UFloatingPawnMovement * Movement;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	UCameraComponent* Camera;

private:
	//상하좌우 입력값 선언
	void UpDown(float NewAxisValue);
	void LeftRight(float NewAxisValue);



};

