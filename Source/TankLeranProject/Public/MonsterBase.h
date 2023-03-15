// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MonsterBase.generated.h"

UCLASS()
class TANKLERANPROJECT_API AMonsterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMonsterBase();

	void Fire();

	UPROPERTY(EditAnywhere)
	float FireRange;
	
	void HandleDestruction();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AProjectile> ProjectClass;

	UPROPERTY(EditAnywhere)
	USceneComponent* ProjectilePoint;

	UPROPERTY(EditAnywhere)
	UParticleSystem* DeathParticle;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
