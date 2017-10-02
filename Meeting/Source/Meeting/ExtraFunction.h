// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "AIController.h"
#include "EnemyCharacter.h"
#include "Perception/AISense_Sight.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AIPerceptionComponent.h"
#include "ExtraFunction.generated.h"

/**
*
*/
UCLASS()
class MEETING_API UExtraFunction : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()


public:
	UFUNCTION(BlueprintCallable, Category = AI)
		static bool SetSightRange(AAIController* Controller, float NewSightRange, float NewLoseSightRange);


};
