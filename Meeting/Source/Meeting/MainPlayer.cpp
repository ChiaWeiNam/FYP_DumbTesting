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
	InputComponent->BindAxis("MoveForward", this, &AMainPlayer::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMainPlayer::MoveRight);
	InputComponent->BindAction("SprintFunction", IE_Pressed, this, &AMainPlayer::SprintFunction);
	InputComponent->BindAction("SprintFunction", IE_Released, this, &AMainPlayer::NoSprintFunction);
}

void AMainPlayer::MoveForward(float speed)
{
	if ((Controller != NULL) && (speed != 0.0f))
	{
		// find out which way is forward
		FRotator Rotation = Controller->GetControlRotation();
		if (GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling())
		{
			Rotation.Pitch = 0.0f;
		}
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		speed *= playerCurrentSpeed;
		AddMovementInput(Direction, speed);
	}
}

void AMainPlayer::MoveRight(float speed)
{
	if ((Controller != NULL) && (speed != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		speed *= playerSpeed;
		AddMovementInput(Direction, speed);
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


