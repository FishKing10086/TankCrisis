// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"

#include "MonsterBase.h"
#include "PlayerTank.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

AEnemyAIController::AEnemyAIController()
{
}

bool AEnemyAIController::InFireRange()
{
	AMonsterBase* SelfMonster =Cast<AMonsterBase>(GetPawn());
	float Distance = FVector::Distance(PlayerPawn->GetActorLocation(),GetPawn()->GetActorLocation());
	return SelfMonster->FireRange >= Distance ? true:false;
}

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();
	

	RunBehaviorTree(BehaviorTree);

	PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
	PlayerTank = Cast<APlayerTank>(UGameplayStatics::GetPlayerPawn(GetWorld(),0));
	
	GetBlackboardComponent()->SetValueAsVector(TEXT("TargetLocation"),PlayerPawn->GetActorLocation());
	GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"),GetPawn()->GetActorLocation());
	GetBlackboardComponent()->SetValueAsObject(TEXT("Target"),PlayerPawn);
}

void AEnemyAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(LineOfSightTo(PlayerTank))
	{
		GetBlackboardComponent()->SetValueAsVector(TEXT("TargetLocation"),PlayerPawn->GetActorLocation());
		GetBlackboardComponent()->SetValueAsVector(TEXT("LastLocation"),PlayerPawn->GetActorLocation());
		GetBlackboardComponent()->SetValueAsBool(TEXT("IsInRange"),InFireRange());
	}
	else
	{
		GetBlackboardComponent()->ClearValue(TEXT("TargetLocation"));
		GetBlackboardComponent()->SetValueAsBool(TEXT("IsInRange"),InFireRange());
	}
}
