#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
class UEnhancedInputLocalPlayerSubsystem;

UCLASS()
class UNREALPROJECT07_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
public:
	AMyPlayerController();
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Controller|IMC")
	UInputMappingContext* IMC;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Controller|Input")
	UInputAction* Move_IA;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Controller|Input")
	UInputAction* Mouse_IA;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Controller|Input")
	UInputAction* Jump_IA;
};
