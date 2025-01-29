// Made by Roberto Reynoso(RvRproduct)

#pragma once

#include "CoreMinimal.h"
#include "State.h"
#include "Shrek.h"

/**
 * 
 */
class GETOUTOFMYSWAMP_API Command
{
public:
	Command();
	virtual ~Command();
	virtual void Execute() = 0;
	AShrek* shrek;

};

class GETOUTOFMYSWAMP_API MoveLeftCommand : public Command
{
public:
	void Execute() override
	{
		shrek->currentState->OnExit(shrek);
		shrek->playerStates->walkState->SetMovement(FVector(-1.0f, 0.0f, 0.0f));
		shrek->currentState = shrek->playerStates->walkState;
		shrek->currentState->OnEnter(shrek);

	};
};

class GETOUTOFMYSWAMP_API MoveRightCommand : public Command
{
public:
	void Execute() override
	{
		shrek->currentState->OnExit(shrek);
		shrek->playerStates->walkState->SetMovement(FVector(1.0f, 0.0f, 0.0f));
		shrek->currentState = shrek->playerStates->walkState;
		shrek->currentState->OnEnter(shrek);
	};
};

class GETOUTOFMYSWAMP_API IdleCommand : public Command
{
public:
	void Execute() override
	{
		shrek->currentState->OnExit(shrek);
		shrek->currentState = shrek->playerStates->idleState;
		shrek->currentState->OnEnter(shrek);
	};
};


class GETOUTOFMYSWAMP_API JumpCommand : public Command
{
public:
	void Execute() override
	{
		shrek->currentState->OnExit(shrek);
		shrek->currentState = shrek->playerStates->jumpState;

		if (shrek)
		shrek->currentState->OnEnter(shrek);
	};
};