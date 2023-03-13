// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBase.h"

#include "Tank.h"
#include "Kismet/GameplayStatics.h"

AEnemyBase::AEnemyBase()
{
}

void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this,0));
	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle,this,&AEnemyBase::CheckFireCondition,FireRate,true);
}

void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if(InFireRange())
	{
		RotateTurret(Tank->GetActorLocation());
	}
}

void AEnemyBase::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}

void AEnemyBase::CheckFireCondition()
{
	if (InFireRange())
	{
		Fire();

	}
}

bool AEnemyBase::InFireRange()
{
	if(Tank)
	{
		float Distance =FVector::Dist(GetActorLocation(),Tank->GetActorLocation());
		if(Distance <= MinDistance)
		{
			return true;
		}
	}
	return false;
}
