// Fill out your copyright notice in the Description page of Project Settings.

#include "Meeting.h"
#include "ExtraFunction.h"

bool UExtraFunction::SetSightRange(AAIController* Controller, float NewSightRange, float NewLoseSightRange)
{
	//UE_LOG(LogTemp, Warning, TEXT("new sight: %f"), NewSightRange);
	if (Controller == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Controller == nullptr"));
		return false;
	}

	FAISenseID Id = UAISense::GetSenseID(UAISense_Sight::StaticClass());
	if (!Id.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Wrong Sense ID"));
		return false;
	}

	UAIPerceptionComponent *Perception = Controller->GetAIPerceptionComponent();
	if (Perception == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Perception == nullptr"));
		return false;
	}

	auto Config = Perception->GetSenseConfig(Id);
	if (Config == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Config == nullptr"));
		return false;
	}

	auto ConfigSight = Cast<UAISenseConfig_Sight>(Config);

	// Save original lose range
	float LoseRange = ConfigSight->LoseSightRadius - ConfigSight->SightRadius;

	ConfigSight->SightRadius = NewSightRange;

	// Apply lose range to new radius of the sight
	if (NewLoseSightRange > NewSightRange)
	{
		ConfigSight->LoseSightRadius = NewLoseSightRange;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Auto Correct Lose Sight"));
		ConfigSight->LoseSightRadius = ConfigSight->SightRadius + LoseRange;
	}
	

	

	Perception->RequestStimuliListenerUpdate();

	return true;
}


