// Fill out your copyright notice in the Description page of Project Settings.
#include "Fonze.h"
#include "CameraLooAt.h"

#include "Hero.h"


// Sets default values
ACameraLooAt::ACameraLooAt()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create our components
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	m_cameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	m_cameraSpringArm->AttachTo(RootComponent);
	m_cameraSpringArm->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 50.0f), FRotator(-80.0f, 0.0f, 0.0f));
	m_cameraSpringArm->TargetArmLength = 400.f;
	m_cameraSpringArm->bEnableCameraLag = true;
	m_cameraSpringArm->CameraLagSpeed = 3.0f;

	// Attach camera spring arm to camera
	m_camera = CreateDefaultSubobject<UCameraComponent>(TEXT("GameCamera"));
	m_camera->AttachTo(m_cameraSpringArm, USpringArmComponent::SocketName);

	// Init attributes
	m_distanceMin = 100.0;
	m_distanceMax = 1000.0;
	m_targetDistance = 100.0;
	m_currentDistance = m_targetDistance;
	m_distanceIncrSpeed = 1.0;

	m_aspectRatio = m_camera->AspectRatio;
	m_cosFieldOfView = FMath::Abs(FMath::Cos(m_camera->FieldOfView));

	for (TActorIterator<AHero> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		//m_heroesPositions.push_back(ActorItr->GetActorLocation());
	}
}

// Called when the game starts or when spawned
void ACameraLooAt::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACameraLooAt::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	int i = 0;
	for (TActorIterator<AHero> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		//m_heroesPositions.at(i) = ActorItr->GetActorLocation();
		++i;
	}

	updatePosition();
	updateDistanceTarget();
	updateDistance();
}

void ACameraLooAt::updatePosition()
{
	FVector averageLocation = FVector(0.f, 0.f, 0.f);
	uint8 numberOfActors = 0;
	/*
	for (int i = 0; i < m_heroesPositions.size(); ++i)
	{
		averageLocation += m_heroesPositions.at(i);
	}

	if (m_heroesPositions.size())
	{
		averageLocation /= m_heroesPositions.size();
		SetActorLocation(averageLocation);
	}
	*/
}

void ACameraLooAt::updateDistanceTarget()
{
	m_targetDistance = m_cosFieldOfView * getMaxHeroesDistance();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("CosA = %f"), m_cosFieldOfView));
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("MaxDist = %f"), getMaxHeroesDistance()));
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("CamDist = %f"), m_targetDistance));
	}

	FMath::Clamp(m_targetDistance, m_distanceMin, m_distanceMax);
}

float ACameraLooAt::getMaxHeroesDistance()
{
	float maxDistance = 0.f;
	/*
	for (int i = 0; i < m_heroesPositions.size(); ++i)
	{
		for (int j = i + 1; j < m_heroesPositions.size(); ++j)
		{
			maxDistance = FMath::Max(maxDistance, FVector::Dist(m_heroesPositions.at(i), m_heroesPositions.at(j)));
		}
	}
	*/

	return maxDistance;
}

void ACameraLooAt::updateDistance()
{
	if (m_targetDistance > m_currentDistance + m_distanceIncrSpeed)
	{
		m_currentDistance += m_distanceIncrSpeed;
		m_cameraSpringArm->TargetArmLength = m_currentDistance;
	}
	else if (m_targetDistance < m_currentDistance - m_distanceIncrSpeed)
	{
		m_currentDistance -= m_distanceIncrSpeed;
		m_cameraSpringArm->TargetArmLength = m_currentDistance;
	}
}


// Called to bind functionality to input
void ACameraLooAt::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
}

