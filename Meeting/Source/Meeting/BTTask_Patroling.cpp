// Fill out your copyright notice in the Description page of Project Settings.

#include "Meeting.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "EnemyCharacter.h"
#include "EnemyAI.h"
#include "BTTask_Patroling.h"



EBTNodeResult::Type UBTTask_Patroling::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AEnemyAI *CharPC = Cast<AEnemyAI>(OwnerComp.GetAIOwner());

	AEnemyCharacter *GetChar = Cast<AEnemyCharacter>(OwnerComp.GetAIOwner()->GetPawn());

	AActor *PPoint1 = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValue<UBlackboardKeyType_Object>(CharPC->Patrol1KeyID));
	AActor *PPoint2 = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValue<UBlackboardKeyType_Object>(CharPC->Patrol2KeyID));

	int32 Point = OwnerComp.GetBlackboardComponent()->GetValueAsInt("CurPoint");
	//AActor *Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	//UE_LOG(LogTemp, Warning, TEXT("current point: %d"), Point);




	if (PPoint1 && PPoint2)
	{
		if (GetChar)
		{
			GetChar->GetCharacterMovement()->MaxWalkSpeed = 250.0f;
			//UE_LOG(LogTemp, Warning, TEXT("MAx Walk Speed: %f"), Test->GetCharacterMovement()->MaxWalkSpeed);
		}

		if (Point == 1)
		{
			CharPC->MoveToActor(PPoint1, 10.0f, true, true, true, 0, true);
			//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, "Point1");
		}
		else if (Point == 2)
		{
			CharPC->MoveToActor(PPoint2, 10.0f, true, true, true, 0, true);
			//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, "point2");

		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, "gg");
		}





		return EBTNodeResult::Succeeded;
	}
	else
	{
		return EBTNodeResult::Failed;

	}

	EBTNodeResult::Failed;
}

