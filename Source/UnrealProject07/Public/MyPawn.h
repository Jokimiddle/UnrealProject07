#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UCapsuleComponent;
class UArrowComponent;
struct FInputActionValue;

UCLASS()
class UNREALPROJECT07_API AMyPawn : public APawn
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "variable");
	float MoveSpeed;

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Component");
	UCapsuleComponent* CapsuleComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Component");
	USkeletalMeshComponent* SkeletalMeshComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Component");
	USpringArmComponent* SpringArmComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Component");
	UCameraComponent* CameraComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Component");
	UArrowComponent* ArrowComponent;

public:	
	AMyPawn();
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void Move_Action(const FInputActionValue& Value);

	UFUNCTION()
	void Mouse_Action(const FInputActionValue& Value);

	UFUNCTION()
	void Jump_Action(const FInputActionValue& Value);

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
