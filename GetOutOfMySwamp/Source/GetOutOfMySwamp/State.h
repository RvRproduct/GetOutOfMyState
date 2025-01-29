// Made by Roberto Reynoso(RvRproduct)

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "Shrek.h"
#include "GameFramework/PawnMovementComponent.h"


/**
 * 
 */
class GETOUTOFMYSWAMP_API State
{
public:
	State();
	virtual ~State();
	virtual void OnEnter(AShrek* shrek) = 0;
	virtual void OnUpdate(AShrek* shrek, float DeltaTime) = 0;
	virtual void OnExit(AShrek* shrek) = 0;
};

class GETOUTOFMYSWAMP_API IdleState : public State
{
public:
	void OnEnter(AShrek* shrek) override
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(
				-1,
				5.f,
				FColor::Yellow,
				FString::Printf(TEXT("Entered Idle State"))
			);
		}
	}

	void OnUpdate(AShrek* shrek, float DeltaTime) override
	{

		shrek->AddActorLocalRotation(FRotator(0.0f, 1.0f, 0.0f));
	}

	void OnExit(AShrek* shrek) override
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(
				-1,
				5.f,
				FColor::Yellow,
				FString::Printf(TEXT("Exited Idle State"))
			);
		}
	}
};

class GETOUTOFMYSWAMP_API WalkState : public State
{
public:

	FVector currentMovement = FVector::Zero();

	void SetMovement(FVector movementDirection)
	{
		currentMovement = movementDirection;
	}



	void OnEnter(AShrek* shrek) override
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(
				-1,
				5.f,
				FColor::Yellow,
				FString::Printf(TEXT("Entered Walk State"))
			);
		}
	}

	void OnUpdate(AShrek* shrek, float DeltaTime) override
	{
		shrek->currentVelocity = (currentMovement * shrek->maxSpeed);
		shrek->AddMovementInput(shrek->currentVelocity);
	}

	void OnExit(AShrek* shrek) override
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(
				-1,
				5.f,
				FColor::Yellow,
				FString::Printf(TEXT("Exited Walk State"))
			);
		}

		shrek->ConsumeMovementInputVector();
	}
};

class GETOUTOFMYSWAMP_API JumpState : public State
{
public:
	void OnEnter(AShrek* shrek) override
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(
				-1,
				5.f,
				FColor::Yellow,
				FString::Printf(TEXT("Entered Jump State"))
			);
		}

		if (shrek->GetCharacterMovement()->IsMovingOnGround())
		{
			shrek->isJumping = false;
		}

		if (!shrek->isJumping)
		{
			shrek->isJumping = true;
			shrek->LaunchCharacter(FVector(0, 0, 500.0f), true, true);
		}
		
	}

	void OnUpdate(AShrek* shrek, float DeltaTime) override
	{
		if (shrek->GetCharacterMovement()->IsMovingOnGround())
		{
			shrek->currentState = shrek->playerStates->idleState;
		}
	}

	void OnExit(AShrek* shrek) override
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(
				-1,
				5.f,
				FColor::Yellow,
				FString::Printf(TEXT("Exited Jump State"))
			);
		}
	}
};


