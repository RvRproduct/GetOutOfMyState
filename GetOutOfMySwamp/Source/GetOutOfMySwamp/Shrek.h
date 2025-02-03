// Made by Roberto Reynoso(RvRproduct)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "PlayerStateManager.h"
#include "SoundManager.h"
#include "Shrek.generated.h"


class State;
class Command;

UCLASS()
class GETOUTOFMYSWAMP_API AShrek : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AShrek();

	State* currentState = nullptr;

	Command
		* aKey,
		* dKey,
		* spacebar,
		* noKey;

	bool isJumping = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sound Manager")
	ASoundManager* soundManager;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player State Manager")
	APlayerStateManager* playerStates;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Speed")
	float maxSpeed = 500;

	FVector currentVelocity = FVector::Zero();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input Mapping")
	class UInputMappingContext* InputMapping;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> JumpAction;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Move(const FInputActionValue& Value);
	void Jump(const FInputActionValue& Value);
};
