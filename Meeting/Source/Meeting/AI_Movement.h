// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "AI_Movement.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MEETING_API UAI_Movement : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UAI_Movement();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void MoveToward(FVector targetLocation);

	void Limit(FVector vector, float limit);

	float LightPara = 0.f;
	bool IsGrow;

private:
	FVector velocity;
	FVector acceleration;

	FVector OriScale;
	FVector* curScale;

	int32 targetIndex;

	

	UPROPERTY(EditAnywhere)
		int32 GrowRate;

	UPROPERTY(EditAnywhere)
		float maxSpeed;

	UPROPERTY(EditAnywhere)
		float maxForce;

	UPROPERTY(EditAnywhere)
		AActor* target[3];


};
