// Fill out your copyright notice in the Description page of Project Settings.

#include "Meeting.h"
#include "EnemyWeakspot.h"
#include "PlayerShoot.h"


// Sets default values for this component's properties
UEnemyWeakspot::UEnemyWeakspot()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEnemyWeakspot::BeginPlay()
{
	Super::BeginPlay();

	bIsRedDamaged = false;
	bIsUVDamaged = false;
	bIsDead = false;

	enemyCurrentHealth = enemyMaxHealth;
}


// Called every frame
void UEnemyWeakspot::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UE_LOG(LogTemp, Error, TEXT("%f"), enemyCurrentHealth);

	if (enemyCurrentHealth <= 0.0f || enemyCurrentHealth >= 40.0f)
	{
		bIsRedDamaged = false;
		bIsUVDamaged = false;
		bIsDead = true;
	}
}