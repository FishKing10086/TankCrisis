// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UCapsuleComponent;
class UBoxComponent;
UCLASS()
class TANKLERANPROJECT_API ABasePawn : public APawn
{
	GENERATED_BODY()


public:
	// Sets default values for this pawn's properties
	ABasePawn();

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UCapsuleComponent* CapsuleComponent;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UStaticMeshComponent* TurretMesh;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	USceneComponent* ProjectilePoint;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UBoxComponent* BoxComponent;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
