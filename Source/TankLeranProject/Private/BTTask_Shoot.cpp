// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Shoot.h"

#include "AIController.h"
#include "MonsterBase.h"

UBTTask_Shoot::UBTTask_Shoot()
{
	NodeName =TEXT("Shoot");
}

EBTNodeResult::Type UBTTask_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	AMonsterBase* Monster = Cast<AMonsterBase>(OwnerComp.GetAIOwner()->GetPawn());
	if(Monster)
	{
		Monster->Fire();
		return EBTNodeResult::Succeeded;
	}
	return  EBTNodeResult::Failed;
}
