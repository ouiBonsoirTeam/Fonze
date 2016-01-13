// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Camera/CameraActor.h"
#include "TopDownCamera.generated.h"

/**
 * 
 */
UCLASS()
class FONZE_API ATopDownCamera : public ACameraActor
{
	GENERATED_BODY()

	public:
		// Sets default values for this pawn's properties
		ATopDownCamera();

		// Called when the game starts or when spawned
		virtual void BeginPlay() override;

		// Called every frame
		virtual void Tick(float DeltaSeconds) override;

		void updateTargetPosition();

	protected:
		UPROPERTY(EditAnywhere)
		USpringArmComponent* OurCameraSpringArm;
		UCameraComponent* OurCamera;
};