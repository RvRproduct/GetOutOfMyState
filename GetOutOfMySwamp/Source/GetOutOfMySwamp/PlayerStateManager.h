// Made by Roberto Reynoso (RvRproduct)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerStateManager.generated.h"

class IdleState;
class WalkState;
class JumpState;

UCLASS()
class GETOUTOFMYSWAMP_API APlayerStateManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayerStateManager();

	IdleState* idleState;
	WalkState* walkState;
	JumpState* jumpState;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
