// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
// #include <vector>
#include "CameraLooAt.generated.h"

UCLASS()
class FONZE_API ACameraLooAt : public APawn
{
	GENERATED_BODY()

	public:
		// Sets default values for this pawn's properties
		ACameraLooAt();

		// Called when the game starts or when spawned
		virtual void BeginPlay() override;
	
		// Called every frame
		virtual void Tick( float DeltaSeconds ) override;
		void updatePosition();
		void updateDistanceTarget();
		void updateDistance();
		float getMaxHeroesDistance();

		// Called to bind functionality to input
		virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	protected:
		UPROPERTY(EditAnywhere)
		USpringArmComponent* m_cameraSpringArm;
		UCameraComponent* m_camera;

		float m_distanceMax;
		float m_distanceMin;
		float m_currentDistance;
		float m_targetDistance;
		float m_distanceIncrSpeed;

		float m_aspectRatio;
		float m_cosFieldOfView;

		// std::vector<FVector> m_heroesPositions;
		
	
	
};
