// Fill out your copyright notice in the Description page of Project Settings.

#include "Fonze.h"
#include "Lootable.h"


// Sets default values
ALootable::ALootable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALootable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALootable::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

