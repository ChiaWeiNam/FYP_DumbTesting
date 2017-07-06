// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "PlayerShoot.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MEETING_API UPlayerShoot : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UPlayerShoot();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	ACharacter* Owner;

	USpotLightComponent* SL_Light = nullptr;
	UStaticMeshComponent* StaticMeshComponent;
	UStaticMesh* StaticMesh;
	UMaterialInstanceDynamic* Mat_LightBeam;

	FLinearColor Red;
	FLinearColor Ultraviolet;

	FVector LineTraceEnd;
	FVector SpotLightLocation;
	FRotator SpotLightRotation;

	float endPoint = 260.0f;
	bool isShoot;
	bool isRedLight;

	void ShootLight();
	void NotShootLight();

	void SwitchLight();
};
