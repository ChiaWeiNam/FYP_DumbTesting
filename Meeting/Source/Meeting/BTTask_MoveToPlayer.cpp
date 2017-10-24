// Fill out your copyright notice in the Description page of Project Settings.

#include "Meeting.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "EnemyCharacter.h"
#include "EnemyAI.h"
#include "BTTask_MoveToPlayer.h"




EBTNodeResult::Type UBTTask_MoveToPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AEnemyAI *CharPC = Cast<AEnemyAI>(OwnerComp.GetAIOwner());

	AActor *Enemy = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValue<UBlackboardKeyType_Object>(CharPC->EnemyKeyID));

	AEnemyCharacter *GetChar = Cast<AEnemyCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	//AActor *Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	float RunSpeed = OwnerComp.GetBlackboardComponent()->GetValueAsFloat("RunSpeed");

	
	if (Enemy)
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsBool("ReachDestination", false);
		if (GetChar)
		{
			GetChar->GetCharacterMovement()->MaxWalkSpeed = RunSpeed;
			//UE_LOG(LogTemp, Warning, TEXT("MAx Walk Speed: %f"), Test->GetCharacterMovement()->MaxWalkSpeed);
		}
		CharPC->MoveToActor(Enemy, 100.0f, true, true, true, 0, true);

		return EBTNodeResult::Succeeded;
	}
	else
	{
		return EBTNodeResult::Failed;

	}

	EBTNodeResult::Failed;
}