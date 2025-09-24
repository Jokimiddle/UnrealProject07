#include "MyPlayerController.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "EnhancedInputSubsystems.h"

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();
	ULocalPlayer* LocalPlayer;
	UEnhancedInputLocalPlayerSubsystem* PlayerSubsystem;

	LocalPlayer = GetLocalPlayer();
	if (LocalPlayer)
	{
		PlayerSubsystem = LocalPlayer->GetSubsystem< UEnhancedInputLocalPlayerSubsystem>();
		if (PlayerSubsystem)
		{
			PlayerSubsystem->AddMappingContext(IMC, 0);
		}
	}
}

AMyPlayerController::AMyPlayerController()
{
	static ConstructorHelpers::FObjectFinder<UInputMappingContext> IMC_Finder(TEXT("/Game/Inpus/IMC_Player.IMC_Player"));
	static ConstructorHelpers::FObjectFinder<UInputAction> Move_IA_Finder(TEXT("/Game/Inpus/IA_Move.IA_Move"));
	static ConstructorHelpers::FObjectFinder<UInputAction> Mouse_IA_Finder(TEXT("/Game/Inpus/IA_Mouse.IA_Mouse"));
	static ConstructorHelpers::FObjectFinder<UInputAction> Jump_IA_Finder(TEXT("/Game/Inpus/IA_Jump.IA_Jump"));

	if (IMC_Finder.Succeeded())
	{
		IMC = IMC_Finder.Object;
	}
	if (Move_IA_Finder.Succeeded())
	{
		Move_IA = Move_IA_Finder.Object;
	}
	if (Mouse_IA_Finder.Succeeded())
	{
		Mouse_IA = Mouse_IA_Finder.Object;
	}
	if (Jump_IA_Finder.Succeeded())
	{
		Jump_IA = Jump_IA_Finder.Object;
	}
}


