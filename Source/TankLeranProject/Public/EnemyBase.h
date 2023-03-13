// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "EnemyBase.generated.h"

/**
 * 
 */
UCLASS()
class TANKLERANPROJECT_API AEnemyBase : public ABasePawn
{
	GENERATED_BODY()
public:
	AEnemyBase();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void HandleDestruction() override;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	class ATank* Tank;

	UPROPERTY(VisibleAnywhere)
	float MinDistance = 800;

	UPROPERTY(VisibleAnywhere)
	float FireRate = 2;

	void CheckFireCondition();

	bool InFireRange();
};
