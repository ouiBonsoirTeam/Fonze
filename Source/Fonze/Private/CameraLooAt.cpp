// Fill out your copyright notice in the Description page of Project Settings.

#include "Fonze.h"
#include "CameraLooAt.h"

#include "Hero.h"


// Sets default values
ACameraLooAt::ACameraLooAt()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create our components
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	OurCameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	OurCameraSpringArm->AttachTo(RootComponent);
	OurCameraSpringArm->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 50.0f), FRotator(-80.0f, 0.0f, 0.0f));
	OurCameraSpringArm->TargetArmLength = 400.f;
	OurCameraSpringArm->bEnableCameraLag = true;
	OurCameraSpringArm->CameraLagSpeed = 3.0f;

	OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("GameCamera"));
	OurCamera->AttachTo(OurCameraSpringArm, USpringArmComponent::SocketName);
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

	updatePosition();
}

void ACameraLooAt::updatePosition()
{
	FVector averageLocation = FVector(0.f, 0.f, 0.f);
	uint8 numberOfActors = 0;

	for (TActorIterator<AHero> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		averageLocation += ActorItr->GetActorLocation();
		++numberOfActors;
	}

	if (numberOfActors)
	{
		averageLocation /= numberOfActors;
		SetActorLocation(averageLocation);
	}
		
}

// Called to bind functionality to input
void ACameraLooAt::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

