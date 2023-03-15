// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyTank.h"

#include "GameFramework/PawnMovementComponent.h"

AEnemyTank::AEnemyTank()
{
	PrimaryActorTick.bCanEverTick = true;
	

}

void AEnemyTank::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemyTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

