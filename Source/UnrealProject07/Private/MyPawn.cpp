#include "MyPawn.h"
#include "Components/CapsuleComponent.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "MyPlayerController.h"
#include "InputActionValue.h"

AMyPawn::AMyPawn()
{
	PrimaryActorTick.bCanEverTick = false;
	MoveSpeed = 5.0f;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	SetRootComponent(CapsuleComponent);

	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	SkeletalMeshComponent->SetupAttachment(RootComponent);

	ArrowComponent = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	ArrowComponent->SetupAttachment(RootComponent);

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComponent->SetupAttachment(RootComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);

	CapsuleComponent->SetCapsuleHalfHeight(84.0f);
	CapsuleComponent->SetCapsuleRadius(25.0f);
	CapsuleComponent->SetSimulatePhysics(false);

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> Mesh_asset(TEXT("/Game/Characters/UEFN_Mannequin/Meshes/SKM_UEFN_Mannequin.SKM_UEFN_Mannequin"));
	if (Mesh_asset.Succeeded())
	{
		SkeletalMeshComponent->SetSkeletalMesh(Mesh_asset.Object);
		SkeletalMeshComponent->SetRelativeLocation(FVector(0.0f, 0.0f, -84.0f));
		SkeletalMeshComponent->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
	}
	SkeletalMeshComponent->SetSimulatePhysics(false);

	SpringArmComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 110.0f));
	SpringArmComponent->bUsePawnControlRotation = false;
	SpringArmComponent->TargetArmLength = 300.0f;

	CameraComponent->SetRelativeRotation(FRotator(-10.0f, 0.0f, 0.0f));
	CameraComponent->bUsePawnControlRotation = false;

}

void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyPawn::Move_Action(const FInputActionValue& Value)
{
	const FVector2D MoveInput2D = Value.Get<FVector2D>();
	if (!FMath::IsNearlyZero(MoveInput2D.X))
	{
		AddActorLocalOffset(FVector(MoveInput2D.X * MoveSpeed, 0.0f, 0.0f));
	}
	if (!FMath::IsNearlyZero(MoveInput2D.Y))
	{
		AddActorLocalOffset(FVector(0.0f, MoveInput2D.Y * MoveSpeed, 0.0f));
	}
}

void AMyPawn::Mouse_Action(const FInputActionValue& Value)
{
	FVector2D MouseInput2D = Value.Get<FVector2D>();
	if (!FMath::IsNearlyZero(MouseInput2D.X))
	{
		AddActorLocalRotation(FRotator(0.0f, MouseInput2D.X, 0.0f));
		
	}
	if (!FMath::IsNearlyZero(MouseInput2D.Y))
	{
		SpringArmComponent->AddLocalRotation(FRotator(MouseInput2D.Y, 0.0f, 0.0f));
	}
}

void AMyPawn::Jump_Action(const FInputActionValue& Value)
{
}

void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* EnhancedInputComponent;
	AMyPlayerController* PlayerController;

	EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (EnhancedInputComponent)
	{
		PlayerController = Cast<AMyPlayerController>(GetController());
		if (PlayerController)
		{
			if (PlayerController->Move_IA)
			{
				EnhancedInputComponent->BindAction(
					PlayerController->Move_IA,
					ETriggerEvent::Triggered,
					this,
					&AMyPawn::Move_Action
				);
			}
			if (PlayerController->Mouse_IA)
			{
				EnhancedInputComponent->BindAction(
					PlayerController->Mouse_IA,
					ETriggerEvent::Triggered,
					this,
					&AMyPawn::Mouse_Action
				);
			}
		}

	}


}

