// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"

#include "Projectile.h"
#include "Kismet//KismetMathLibrary.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/CapsuleComponent.h"


// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CapsuleComponent"));
	BoxComponent ->SetupAttachment(RootComponent) ;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	BaseMesh->SetupAttachment(BoxComponent);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TurretMesh"));
	TurretMesh->SetupAttachment(BaseMesh);

	ProjectilePoint = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectilePoint"));
	ProjectilePoint->SetupAttachment(TurretMesh);


}

// Called when the game starts or when spawned
void ABasePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABasePawn::RotateTurret(FVector LookAtTarget)
{
	FVector ToTarget = LookAtTarget -  TurretMesh->GetComponentLocation();
	FRotator LookAtRotation =FRotator(0, ToTarget.Rotation().Yaw,0);
	TurretMesh->SetWorldRotation(FMath::RInterpTo(TurretMesh->GetComponentRotation(),LookAtRotation,UGameplayStatics::GetWorldDeltaSeconds(this),25));
	
}

void ABasePawn::Fire()
{
	FActorSpawnParameters SpawnParam;
	if(ProjectClass.Get())
	{
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectClass,ProjectilePoint->GetComponentLocation(),ProjectilePoint->GetComponentRotation(),SpawnParam);
		Projectile->SetOwner(this);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1,2.f,FColor::Red,TEXT("NoSettingAmmoClass"));
	}
	
}

void ABasePawn::HandleDestruction()
{
}

// Called every frame
void ABasePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



