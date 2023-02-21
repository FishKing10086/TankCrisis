// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TANKLERANPROJECT_API ATank : public ABasePawn
{
	GENERATED_BODY()
public:
	ATank();

	UPROPERTY(VisibleAnywhere)
	float Speed = 500;

	UPROPERTY(VisibleAnywhere)
	float TurnSpeed = 90;
private:
	void Fire();

	void MoveForward(float Value);

	void MoveRight(float Value);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
};

	
	

