// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"

#include "Kismet/GameplayStatics.h"

ATank::ATank()
{
	Speed = 1000;
	TurnSpeed = 250;
}

void ATank::HandleDestruction()
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
		SetActorHiddenInGame(true);
		SetActorTickEnabled(false);
}
