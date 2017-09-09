// Fill out your copyright notice in the Description page of Project Settings.

#include "Meeting.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "EnemyCharacter.h"
#include "EnemyAI.h"

AEnemyAI::AEnemyAI()
{
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));
	BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));

	ReachDest = true;


}

void AEnemyAI::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);

	AEnemyCharacter *Char = Cast<AEnemyCharacter>(InPawn);

	if (Char && Char->BotBehavior)
	{

		BlackboardComp->InitializeBlackboard(*Char->BotBehavior->BlackboardAsset);

		EnemyKeyID = BlackboardComp->GetKeyID("Target");
		Patrol1KeyID = BlackboardComp->GetKeyID("PatrolPoint1");
		Patrol2KeyID = BlackboardComp->GetKeyID("PatrolPoint2");

		BehaviorComp->StartTree(*Char->BotBehavior);

		BlackboardComp->SetValueAsBool("ReachDestination", ReachDest);

	}
}

void AEnemyAI::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result)
{
	if (Result.Code == EPathFollowingResult::Success) {
		ReachDest = true;
		BlackboardComp->SetValueAsBool("ReachDestination", ReachDest);
	}
	else if (Result.Code == EPathFollowingResult::Blocked) {
		ReachDest = false;
		BlackboardComp->SetValueAsBool("ReachDestination", ReachDest);

	}
}
