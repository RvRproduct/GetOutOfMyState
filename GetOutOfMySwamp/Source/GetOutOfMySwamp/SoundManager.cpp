// Made by Roberto Reynoso (RvRproduct)


#include "SoundManager.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASoundManager::ASoundManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASoundManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASoundManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASoundManager::PlaySound(USoundWave* sound, FVector location)
{
	if (sound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, sound, location);
	}
}

