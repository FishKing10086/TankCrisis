// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "EnemyBase.h"
#include "Tower.generated.h"

/**
 * 
 */
UCLASS()
class TANKLERANPROJECT_API ATower : public AEnemyBase
{
	GENERATED_BODY()
	
public:
	ATower();

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	


};
