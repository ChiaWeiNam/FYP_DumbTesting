// Fill out your copyright notice in the Description page of Project Settings.

#include "Meeting.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "EnemyCharacter.h"
#include "EnemyAI.h"
#include "BTTask_UpdatePatrolPoint.h"




EBTNodeResult::Type UBTTask_UpdatePatrolPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AEnemyAI *CharPC = Cast<AEnemyAI>(OwnerComp.GetAIOwner());

	int32 Point = OwnerComp.GetBlackboardComponent()->GetValueAsInt("CurPoint");

	//AActor *Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

	if (Point)
	{
		if (Point == 1)
		{
			OwnerComp.GetBlackboardComponent()->SetValueAsInt("CurPoint", 2);
		}
		else if (Point == 2)
		{
			OwnerComp.GetBlackboardComponent()->SetValueAsInt("CurPoint", 1);
		}


		return EBTNodeResult::Succeeded;
	}
	else
	{
		return EBTNodeResult::Failed;

	}

	EBTNodeResult::Failed;
}