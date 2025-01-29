// Made by Roberto Reynoso(RvRproduct)

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class GETOUTOFMYSWAMP_API Command
{
public:
	Command();
	virtual ~Command();
	virtual void Execute() = 0;
};

class GETOUTOFMYSWAMP_API MoveLeftCommand : public Command
{
public:
	void Execute() override
	{

	};
};

class GETOUTOFMYSWAMP_API MoveRightCommand : public Command
{
public:
	void Execute() override
	{

	};
};

class GETOUTOFMYSWAMP_API JumpCommand : public Command
{
public:
	void Execute() override
	{

	};
};