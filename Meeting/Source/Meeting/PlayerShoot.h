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

	UPROPERTY(EditAnywhere, BluePrintReadWrite)
		bool isAiming;

	UPROPERTY(EditAnywhere, BluePrintReadWrite)
		bool isShoot;

	UPROPERTY(EditAnywhere, BluePrintReadWrite)
		float ammoLimit;

private:
	ACharacter* Owner;

	USkeletalMeshComponent* CharacterMesh;
	USceneComponent* GunMesh;
	USceneComponent* LaserSource;
	UParticleSystemComponent* LaserSight;

	USpotLightComponent* SL_Light;
	UStaticMeshComponent* StaticMeshComponent;
	UStaticMesh* StaticMesh;
	UMaterialInstanceDynamic* Mat_LightBeam;

	FLinearColor RedBeam;
	FLinearColor UltravioletBeam;
	FLinearColor RedSpot;
	FLinearColor UltravioletSpot;

	FVector LineTraceEnd;
	FVector SpotLightLocation;
	FRotator SpotLightRotation;

	float endPoint;
	bool isRedLight;

	void ShootLight();
	void NotShootLight();

	void SwitchLight();
};
