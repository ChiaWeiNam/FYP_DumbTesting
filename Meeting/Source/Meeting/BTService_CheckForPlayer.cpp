// Fill out your copyright notice in the Description page of Project Settings.

#include "Meeting.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "EnemyCharacter.h"
#include "EnemyAI.h"
#include "MainPlayer.h"
#include "BTService_CheckForPlayer.h"


UBTService_CheckForPlayer::UBTService_CheckForPlayer()
{
	bCreateNodeInstance = true;
}

void UBTService_CheckForPlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	AEnemyAI *EnemyPC = Cast<AEnemyAI>(OwnerComp.GetAIOwner());

	if (EnemyPC)
	{
		//AMainPlayer *Enemy = Cast<AMainPlayer>(GetWorld()->GetFirstPlayerController()->GetPawn());

		AActor *Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

		if (Player)
		{
			OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(EnemyPC->EnemyKeyID, Player);
			//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, "Enemy Is Here");
		}
		else
		{
			//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, "Enemy Is not Here");
		}
	}
}
