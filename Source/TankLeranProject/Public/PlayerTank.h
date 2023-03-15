// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "PlayerTank.generated.h"

/**
 * 
 */
UCLASS()
class TANKLERANPROJECT_API APlayerTank : public ATank
{
	GENERATED_BODY()
public:
	APlayerTank();
	
	UPROPERTY()
	APlayerController* TankPlayerController;
	

	
	virtual void Fire() override;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	void MoveForward(float Value);

	void MoveRight(float Value);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
