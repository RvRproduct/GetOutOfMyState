// Made by Roberto Reynoso(RvRproduct)


#include "Shrek.h"
#include "Command.h"
#include "AllPlayerStates.h"

// Sets default values
AShrek::AShrek()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	aKey = nullptr;
	dKey = nullptr;
	spacebar = nullptr;
	noKey = nullptr;
}

// Called when the game starts or when spawned
void AShrek::BeginPlay()
{
	Super::BeginPlay();

	aKey = new MoveLeftCommand();
	aKey->shrek = this;
	dKey = new MoveRightCommand();
	dKey->shrek = this;
	spacebar = new JumpCommand();
	spacebar->shrek = this;
	noKey = new IdleCommand();
	noKey->shrek = this;

	currentState = playerStates->idleState;
}

// Called every frame
void AShrek::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (currentState != nullptr)
	{
		currentState->OnUpdate(this, DeltaTime);
	}
	
}

// Called to bind functionality to input
void AShrek::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(InputMapping, 0);
		}
	}

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Binding Each Input
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AShrek::Move);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AShrek::Jump);
	}

}

void AShrek::Move(const FInputActionValue& Value)
{
	FVector movementInput = Value.Get<FVector>();

	if (movementInput.X < 0) // Left
	{
		aKey->Execute();
	}
	else if (movementInput.X > 0) // Right
	{
		dKey->Execute();
	}
	else if (movementInput.X == 0)
	{
		noKey->Execute();
	}
}

void AShrek::Jump(const FInputActionValue& Value)
{
	if (Value.Get<bool>())
	{
		spacebar->Execute();
	}
}



