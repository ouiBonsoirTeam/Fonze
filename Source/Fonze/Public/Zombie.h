// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FonzeCharacter.h"
#include "Zombie.generated.h"

UCLASS()
class FONZE_API AZombie : public AFonzeCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AZombie();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	
	
};
