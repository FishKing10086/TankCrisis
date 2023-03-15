// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBase.h"

#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystem.h"
#include "UObject/ConstructorHelpers.h"

AEnemyBase::AEnemyBase()
{

	static ConstructorHelpers::FObjectFinder<UParticleSystem> Partical(TEXT("/Game/Assets/Effects/P_DeathEffect.P_DeathEffect"));
	if(Partical.Succeeded())
	{
		DeathParticle = Partical.Object;
	}
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
	
	if(DeathParticle  != nullptr)
	{
		
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(),DeathParticle,GetActorLocation());
	}
	else
	{
		UE_LOG(LogTemp,Warning,TEXT("DeathParticle NOT Setting!!!"));
	}
	
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
