// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "BaseLevel.generated.h"

UCLASS()
class CPPEXAM_API ABaseLevel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseLevel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "My Triggers")
	UBoxComponent* Trigger;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "My Triggers")
	UBoxComponent* SpawnLoacation;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "My Triggers")
	UBoxComponent* PowerUpSpawnLoacation;

public:
	UBoxComponent* GetTrigger();
	UBoxComponent* GetSpawnLocation();
	UBoxComponent* GetPowerupSpawnLocation();
};
