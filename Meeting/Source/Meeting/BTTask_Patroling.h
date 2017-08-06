// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_Patroling.generated.h"

/**
 * 
 */
UCLASS()
class MEETING_API UBTTask_Patroling : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

	
public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
	
};
