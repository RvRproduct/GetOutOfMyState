// Made by Roberto Reynoso(RvRproduct)


#include "Shrek.h"

// Sets default values
AShrek::AShrek()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AShrek::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShrek::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShrek::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

