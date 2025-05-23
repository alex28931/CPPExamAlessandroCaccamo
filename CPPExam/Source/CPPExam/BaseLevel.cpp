// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseLevel.h"

// Sets default values
ABaseLevel::ABaseLevel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseLevel::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABaseLevel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UBoxComponent* ABaseLevel::GetTrigger()
{
	return Trigger;
}

UBoxComponent* ABaseLevel::GetSpawnLocation()
{
	return SpawnLoacation;
}

UBoxComponent* ABaseLevel::GetPowerupSpawnLocation()
{
	return PowerUpSpawnLoacation;
}

