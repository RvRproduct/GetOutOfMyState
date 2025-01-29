// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class GETOUTOFMYSWAMP_API State
{
public:
	State();
	virtual ~State();
	virtual void OnEnter() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnExit() = 0;
};

class GETOUTOFMYSWAMP_API IdleState : public State
{
public:
	void OnEnter() override
	{

	}

	void OnUpdate() override
	{

	}

	void OnExit() override
	{

	}
};

class GETOUTOFMYSWAMP_API WalkState : public State
{
public:
	void OnEnter() override
	{

	}

	void OnUpdate() override
	{

	}

	void OnExit() override
	{

	}
};

class GETOUTOFMYSWAMP_API JumpState : public State
{
public:
	void OnEnter() override
	{

	}

	void OnUpdate() override
	{

	}

	void OnExit() override
	{

	}
};


