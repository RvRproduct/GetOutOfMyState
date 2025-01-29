// Made by Roberto Reynoso(RvRproduct)

#pragma once

#include "CoreMinimal.h"
#include "Shrek.h"
#include "State.h"

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
	IdleState* idleState = new IdleState();
	WalkState* walkState = new WalkState();
	JumpState* jumpState = new JumpState();

};

class GETOUTOFMYSWAMP_API MoveLeftCommand : public Command
{
public:
	void Execute() override
	{
		shrek->currentState->OnExit(shrek);
		walkState->SetMovement(FVector(-1.0f, 0.0f, 0.0f));
		shrek->currentState = walkState;
		shrek->currentState->OnEnter(shrek);

	};
};

class GETOUTOFMYSWAMP_API MoveRightCommand : public Command
{
public:
	void Execute() override
	{
		shrek->currentState->OnExit(shrek);
		walkState->SetMovement(FVector(1.0f, 0.0f, 0.0f));
		shrek->currentState = walkState;
		shrek->currentState->OnEnter(shrek);
	};
};

class GETOUTOFMYSWAMP_API IdleCommand : public Command
{
public:
	void Execute() override
	{
		shrek->currentState->OnExit(shrek);
		shrek->currentState = idleState;
		shrek->currentState->OnEnter(shrek);
	};
};


class GETOUTOFMYSWAMP_API JumpCommand : public Command
{
public:
	void Execute() override
	{
		shrek->currentState->OnExit(shrek);
		shrek->currentState = jumpState;
		shrek->currentState->OnEnter(shrek);
	};
};