// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "EnemyWeakspot.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MEETING_API UEnemyWeakspot : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UEnemyWeakspot();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BluePrintReadWrite)
		float enemyMaxHealth;

	UPROPERTY(EditAnywhere, BluePrintReadWrite)
		float enemyCurrentHealth;

	UPROPERTY(EditAnywhere, BluePrintReadWrite)
		bool bIsRedDamaged;

	UPROPERTY(EditAnywhere, BluePrintReadWrite)
		bool bIsUVDamaged;

	UPROPERTY(EditAnywhere, BluePrintReadWrite)
		bool bIsDead;
};
