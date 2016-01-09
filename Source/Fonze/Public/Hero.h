// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FonzeCharacter.h"
#include "Hero.generated.h"

UCLASS()
class FONZE_API AHero : public AFonzeCharacter
{
	GENERATED_BODY()

	FName m_name;

public:
	// Sets default values for this character's properties
	AHero();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	
	
};
