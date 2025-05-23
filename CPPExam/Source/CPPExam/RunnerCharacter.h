// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "MyHUD.h"
#include "RunnerCharacter.generated.h"

UCLASS()
class CPPEXAM_API ARunnerCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* SideViewCamera;
	UPROPERTY(EditAnywhere,Category="Materials")
	UMaterialInterface* DefaultMaterialZero;
	UPROPERTY(EditAnywhere, Category = "Materials")
	UMaterialInterface* DefaultMaterialOne;
	UPROPERTY(EditAnywhere, Category = "Materials")
	UMaterialInterface* PowerUpMaterial;

public:

	ARunnerCharacter();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UCameraComponent* GetSideViewCamera()
	{
		return SideViewCamera;
	}

	void RestartLevel();

	bool LoadGame(FString SlotName, int32 UserIndex);

	bool SaveGame(FString SlotName, int32 UserIndex);

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:

	virtual void BeginPlay() override;

	void MoveRight(float value);
	
	void Death();

	void ResetAbilities();

	UPROPERTY(EditAnywhere, Category="Widget Type")
	TSubclassOf<UUserWidget> WidgetClass;
	UMyHUD* MyHud;

private:

	FVector TempPos = FVector();
	float ZPosition;
	bool bCanMove;
	FTimerHandle TimerForResetVelocity;

public:
	float TimeRecord;
	float CurrentTime;
};
