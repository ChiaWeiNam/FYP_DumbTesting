// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "MainPlayer.generated.h"

UCLASS()
class MEETING_API AMainPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	float playerSpeed = 0.5f;

	float playerMaxSpeed = 1.0f;

	float playerCurrentSpeed = playerSpeed;

	void MoveFront(float speed);

	void MoveBack(float speed);

	void MoveRight(float speed);

	void MoveLeft(float speed);

	void SprintFunction();

	void NoSprintFunction();
};
