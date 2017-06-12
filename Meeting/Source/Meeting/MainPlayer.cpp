// Fill out your copyright notice in the Description page of Project Settings.

#include "Meeting.h"
#include "MainPlayer.h"


// Sets default values
AMainPlayer::AMainPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMainPlayer::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMainPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("MoveFront", this, &AMainPlayer::MoveFront);
	InputComponent->BindAxis("MoveBack", this, &AMainPlayer::MoveBack);
	InputComponent->BindAxis("MoveRight", this, &AMainPlayer::MoveRight);
	InputComponent->BindAxis("MoveLeft", this, &AMainPlayer::MoveLeft);
	InputComponent->BindAction("SprintFunction", IE_Pressed, this, &AMainPlayer::SprintFunction);
	InputComponent->BindAction("SprintFunction", IE_Released, this, &AMainPlayer::NoSprintFunction);
}

void AMainPlayer::MoveFront(float speed)
{
	if (Controller && speed)
	{
		speed = playerCurrentSpeed;
		AddMovementInput(GetActorForwardVector(), speed);
	}
}

void AMainPlayer::MoveBack(float speed)
{
	if (Controller && speed)
	{
		speed = -(playerCurrentSpeed /4);
		AddMovementInput(GetActorForwardVector(), speed);
	}
}

void AMainPlayer::MoveRight(float speed)
{
	if (Controller && speed)
	{
		speed = playerCurrentSpeed;
		AddMovementInput(GetActorRightVector(), speed);
	}
}

void AMainPlayer::MoveLeft(float speed)
{
	if (Controller && speed)
	{
		speed = -playerCurrentSpeed;
		AddMovementInput(GetActorRightVector(), speed);
	}
}

void AMainPlayer::SprintFunction()
{
	playerCurrentSpeed = playerMaxSpeed;
}

void AMainPlayer::NoSprintFunction()
{
	playerCurrentSpeed = playerSpeed;
}
