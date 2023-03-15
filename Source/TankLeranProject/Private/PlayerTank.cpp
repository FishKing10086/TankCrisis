// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerTank.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/InputComponent.h"
#include "Kismet/KismetMathLibrary.h"

APlayerTank::APlayerTank()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(BaseMesh);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);


}




void APlayerTank::Fire()
{
	Super::Fire();
}

void APlayerTank::BeginPlay()
{
	Super::BeginPlay();
	TankPlayerController = Cast<APlayerController>(GetController());
}

void APlayerTank::MoveForward(float Value)
{
	if(Value != 0)
	{
		FVector DeltaVector(0.f);
		Value =Value * Speed *UGameplayStatics::GetWorldDeltaSeconds(this);
		
		DeltaVector.X=Value;
		AddActorLocalOffset(DeltaVector,true);


	}
}

void APlayerTank::MoveRight(float Value)
{
	if(Value != 0)
	{
		FRotator Rotation(0.f);
		Value =Value* TurnSpeed * UGameplayStatics::GetWorldDeltaSeconds(this);

		Rotation.Yaw = Value;
		AddActorLocalRotation(Rotation,true);
		
	}
}

void APlayerTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(TankPlayerController)
	{
		FHitResult HitResult;
		bool HasHit = TankPlayerController->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility,false,HitResult);
		if(HasHit)
		{
			DrawDebugSphere(GetWorld(),HitResult.ImpactPoint,25,12,FColor::Red,false,-1);

			RotateTurret(HitResult.ImpactPoint);
		}
	}
}

void APlayerTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction(TEXT("Fire"),EInputEvent::IE_Pressed,this,&APlayerTank::Fire);
	PlayerInputComponent->BindAxis(TEXT("Moveforad"),this,&APlayerTank::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"),this,&APlayerTank::MoveRight);
}

