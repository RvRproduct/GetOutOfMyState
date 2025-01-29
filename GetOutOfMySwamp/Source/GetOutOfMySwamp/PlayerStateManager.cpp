// Made by Roberto Reynoso (RvRproduct)


#include "PlayerStateManager.h"
#include "State.h"

// Sets default values
APlayerStateManager::APlayerStateManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	idleState = new IdleState();
	walkState = new WalkState();
	jumpState = new JumpState();

}

// Called when the game starts or when spawned
void APlayerStateManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerStateManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

