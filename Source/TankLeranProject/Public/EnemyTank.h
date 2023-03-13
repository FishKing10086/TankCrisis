// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "Tower.h"
#include "EnemyTank.generated.h"

/**
 * 
 */
UCLASS()
class TANKLERANPROJECT_API AEnemyTank : public AEnemyBase
{
	GENERATED_BODY()
public:
	AEnemyTank();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
