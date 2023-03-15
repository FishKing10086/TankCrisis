// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterBase.h"

#include "Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMonsterBase::AMonsterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ProjectilePoint = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectilePoint"));
	ProjectilePoint->SetupAttachment(RootComponent);

	FireRange = 700;
}

void AMonsterBase::HandleDestruction()
{
	if(DeathParticle != nullptr)
	{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(),DeathParticle,GetActorLocation());
	}
	else
	{
		UE_LOG(LogTemp,Warning,TEXT("DeathParticle NOT Setting!!!"));
	}
	Destroy();
}

// Called when the game starts or when spawned
void AMonsterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMonsterBase::Fire()
{
	FActorSpawnParameters SpawnParam;
	if(ProjectClass.Get())
	{
		//auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectClass,ProjectilePoint->GetComponentLocation(),ProjectilePoint->GetComponentRotation(),SpawnParam);

		AProjectile* Projectile = Cast<AProjectile>(UGameplayStatics::BeginDeferredActorSpawnFromClass(this,ProjectClass,ProjectilePoint->GetComponentTransform(),ESpawnActorCollisionHandlingMethod::AlwaysSpawn,this));
		if(Projectile)
		{
			Projectile->ProjectileComponent->InitialSpeed = FireRange + 1500;
		}
		UGameplayStatics::FinishSpawningActor(Projectile,ProjectilePoint->GetComponentTransform());
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1,2.f,FColor::Red,TEXT("NoSettingAmmoClass"));
	}
	
}



// Called every frame
void AMonsterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMonsterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

