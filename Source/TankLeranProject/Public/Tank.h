// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "EnemyBase.h"
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

	virtual void HandleDestruction() override;

	UPROPERTY(EditAnywhere)
	UParticleSystem* DeathParticle;

	UPROPERTY(VisibleAnywhere)
	float Speed = 500;

	UPROPERTY(VisibleAnywhere)
	float TurnSpeed = 90;
};

	
	

