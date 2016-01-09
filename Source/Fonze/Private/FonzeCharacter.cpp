// Fill out your copyright notice in the Description page of Project Settings.

#include "Fonze.h"
#include "FonzeCharacter.h"


// Sets default values
AFonzeCharacter::AFonzeCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFonzeCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFonzeCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AFonzeCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

