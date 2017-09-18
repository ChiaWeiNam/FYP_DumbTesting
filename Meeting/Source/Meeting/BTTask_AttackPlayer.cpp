// Fill out your copyright notice in the Description page of Project Settings.

#include "Meeting.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "EnemyCharacter.h"
#include "EnemyAI.h"
#include "BTTask_AttackPlayer.h"


EBTNodeResult::Type UBTTask_AttackPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AEnemyAI *CharPC = Cast<AEnemyAI>(OwnerComp.GetAIOwner());

	AActor *Enemy = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValue<UBlackboardKeyType_Object>(CharPC->EnemyKeyID));

	AEnemyCharacter *GetChar = Cast<AEnemyCharacter>(OwnerComp.GetAIOwner()->GetPawn());

	bool attack = OwnerComp.GetBlackboardComponent()->GetValueAsBool("Attacking");
	//AActor *Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

	if (Enemy)
	{
		if (attack == false)
		{
			OwnerComp.GetBlackboardComponent()->SetValueAsBool("Attacking", true);
			OwnerComp.GetBlackboardComponent()->SetValueAsBool("InAttackRange", true);
		}

		return EBTNodeResult::Succeeded;
	}
	else
	{
		return EBTNodeResult::Failed;

	}

	EBTNodeResult::Failed;
}

