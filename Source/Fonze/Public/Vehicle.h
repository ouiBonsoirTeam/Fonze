// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Vehicle.generated.h"

UCLASS()
class FONZE_API AVehicle : public APawn
{
	GENERATED_BODY()

	uint8 m_healthPoint;
	uint8 m_speed;

public:
	// Sets default values for this pawn's properties
	AVehicle();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	
	
};
