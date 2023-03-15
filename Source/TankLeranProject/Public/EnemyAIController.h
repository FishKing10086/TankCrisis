// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class TANKLERANPROJECT_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
public:
	AEnemyAIController();
	UPROPERTY()
	class APlayerTank* PlayerTank;

	UPROPERTY(EditAnywhere)
	UBehaviorTree* BehaviorTree; 
	
	bool InFireRange();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	APawn* PlayerPawn;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
