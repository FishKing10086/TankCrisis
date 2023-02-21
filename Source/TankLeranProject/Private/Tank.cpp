// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"



ATank::ATank()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(BaseMesh);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
}

void ATank::Fire()
{

}

void ATank::MoveForward(float Value)
{
	if(Value != 0)
	{
		FVector DeltaVector(0.f);
		Value =Value * Speed *UGameplayStatics::GetWorldDeltaSeconds(this);
		
		DeltaVector.X=Value;
		AddActorLocalOffset(DeltaVector,true);
	}
}

void ATank::MoveRight(float Value)
{
	if(Value != 0)
	{
		FRotator Rotation(0.f);
		Value =Value* TurnSpeed * UGameplayStatics::GetWorldDeltaSeconds(this);

		Rotation.Yaw = Value;
		AddActorLocalRotation(Rotation,true);
		
	}
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
}

void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("Fire"),EInputEvent::IE_Pressed,this,&ATank::Fire);
	PlayerInputComponent->BindAxis(TEXT("Moveforad"),this,&ATank::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"),this,&ATank::MoveRight);
}

