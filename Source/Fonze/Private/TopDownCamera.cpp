// Fill out your copyright notice in the Description page of Project Settings.

#include "Fonze.h"
#include "TopDownCamera.h"

#include "Hero.h"


ATopDownCamera::ATopDownCamera()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create our components
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	OurCameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	OurCameraSpringArm->AttachTo(RootComponent);
	OurCameraSpringArm->SetRelativeLocationAndRotation(FVector(0.0f, 200.0f, 00.0f), FRotator(0.0f, 0.0f, 0.0f));
	OurCameraSpringArm->TargetArmLength = 400.f;
	// OurCameraSpringArm->SetWorldRotation(FRotator(90.0f, 90.0f, 90.0f));
	OurCameraSpringArm->bEnableCameraLag = true;
	OurCameraSpringArm->CameraLagSpeed = 1.0f;
	OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("GameCamera"));
	OurCamera->AttachTo(OurCameraSpringArm, USpringArmComponent::SocketName);

}

// Called when the game starts or when spawned
void ATopDownCamera::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ATopDownCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	updateTargetPosition();
}

void ATopDownCamera::updateTargetPosition()
{
	FVector averageLocation = FVector(0.f, 0.f, 0.f);
	uint8 numberOfActors = 0;

	for (TActorIterator<AHero> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		averageLocation += ActorItr->GetActorLocation();
		++numberOfActors;
	}

	averageLocation /= numberOfActors;
	SetActorLocation(averageLocation);
}

/*
ATopDownCamera::ATopDownCamera()
{
	m_target = AActor();
}

ATopDownCamera::ATopDownCamera(float distanceMin, float distanceMax) : m_distanceMin(distanceMin), m_distanceMax(distanceMax)
{
	m_distance = distanceMin;
	m_target = AActor();

	PrimaryActorTick.bCanEverTick = true;
}

void ATopDownCamera::BeginPlay()
{
	Super::BeginPlay();
}

void ATopDownCamera::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	clampDistance();
	updateTargetPosition();
	lookAtTarget();
	computeLimitRadius();
}

void ATopDownCamera::updateTargetPosition()
{
	FVector averageLocation = FVector(0.f, 0.f, 0.f);
	uint8 numberOfActors = 0;

	for (TActorIterator<AHero> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		averageLocation += ActorItr->GetActorLocation();
		++numberOfActors;
	}

	averageLocation /= numberOfActors;
	m_target = averageLocation;
}

void ATopDownCamera::lookAtTarget()
{
	SetActorRotation((m_target - GetActorLocation()).Rotation());

	// FVector selfieStick = m_target + FVector(0, 100, 200) * m_distance;
	// SetActorLocation(selfieStick);
	// SetActorRotation((m_target - selfieStick).Rotation());
}

void ATopDownCamera::clampDistance()
{
	FMath::Clamp(m_distance, m_distanceMin, m_distanceMax);
}

float ATopDownCamera::computeLimitRadius()
{
	return 1.0;
}
*/

/*
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("POSITION: (%f, %f)"), averageXPosition, averageYPosition));
	}
*/