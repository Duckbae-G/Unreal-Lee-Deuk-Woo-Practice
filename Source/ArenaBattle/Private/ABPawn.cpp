// Fill out your copyright notice in the Description page of Project Settings.

#include "ABPawn.h"


// Sets default values
AABPawn::AABPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 헤더에서 정의된 컴포넌트 구현
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CAPSULE"));
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MESH"));
	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MOVEMENT"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	// 캡슐을 루트 컴포넌트로 설정하고 나머지 컴포넌트를 캡슐에 붙여줌
	RootComponent = Capsule;
	Mesh->SetupAttachment(Capsule);
	SpringArm->SetupAttachment(Capsule);
	//카메라는 스프링암에 붙어야함
	Camera->SetupAttachment(SpringArm);

	//캡슐의 기본 높이와 둘레를 정해주고, 
	// 메쉬가 캡슐에 들어가도록 메쉬의 Z벡터를 내려주고(안그러면 캡슐이 발밑에 있음) 방향를 돌려줌.(위치 돌리는 이유 = 언리얼엔진과 3D제작툴의 방향차이)
	Capsule->SetCapsuleHalfHeight(88.0f);
	Capsule->SetCapsuleRadius(34.0f);
	Mesh->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -88.0f), FRotator(0.0f, -90.0f, 0.0f));
	//SpringArm의 거리 설정과 각도 설정
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->SetRelativeRotation(FRotator(-15.0f, 0.0f, 0.0f));

	//해당 경로의 Cardboard 스켈레탈메쉬 가져오기
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_CARDBOARD(TEXT("/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Cardboard.SK_CharM_Cardboard"));

	//가져오는데 성공했으면 스켈레탈메쉬 적용
	if (SK_CARDBOARD.Succeeded())
	{
		Mesh->SetSkeletalMesh(SK_CARDBOARD.Object);
	}

	Mesh->SetAnimationMode(EAnimationMode::AnimationBlueprint);

	static ConstructorHelpers::FClassFinder<UAnimInstance> WARRIOR_ANIM(TEXT("/Game/Book/Animations/WarriorAnimBluePrint.WarriorAnimBluePrint_C"));
	if (WARRIOR_ANIM.Succeeded())
	{
		Mesh->SetAnimInstanceClass(WARRIOR_ANIM.Class);
	}
}

// Called when the game starts or when spawned
void AABPawn::BeginPlay()
{
	Super::BeginPlay();


}

// Called every frame
void AABPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AABPawn::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	ABLOG_S(Warning);
}

void AABPawn::PossessedBy(AController * NewController)
{
	ABLOG_S(Warning);
	Super::PossessedBy(NewController);
}


// Called to bind functionality to input
void AABPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//헤더에서 정의한 상하좌우값 입력 설정의 이름과 이와 연동할 언리얼 오브젝트 인스턴스의 함수 포인터 지정
	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AABPawn::UpDown);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AABPawn::LeftRight);
}

////밸류값 로그 띄우기, AddMovemenetInput으로 폰 상하좌우 조종
void AABPawn::UpDown(float NewAxisValue)
{
	//ABLOG(Warning, TEXT("%f"), NewAxisValue);
	AddMovementInput(GetActorForwardVector(), NewAxisValue);
}
void AABPawn::LeftRight(float NewAxisValue)
{
	//ABLOG(Warning, TEXT("%f"), NewAxisValue);
	AddMovementInput(GetActorRightVector(), NewAxisValue);
}
