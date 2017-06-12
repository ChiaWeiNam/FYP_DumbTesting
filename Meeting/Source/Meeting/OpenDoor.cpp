// Fill out your copyright notice in the Description page of Project Settings.

#include "Meeting.h"
#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	//OpenDoor();

	Owner = GetOwner();
	MainPlayer = GetWorld()->GetFirstPlayerController()->GetCharacter();

	// ...
	
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (TriggerBox->IsOverlappingActor(MainPlayer))
	{
		OpenDoor();
	}

	// ...
}

void UOpenDoor::OpenDoor()
{
	//FVector finalLocation = Owner->GetActorLocation() + openDoorLocation;
	FVector finalLocation;
	finalLocation.X = Owner->GetActorLocation().X + openDoorLocation.X;
	finalLocation.Y = Owner->GetActorLocation().Y + openDoorLocation.Y;
	finalLocation.Z = Owner->GetActorLocation().Z + openDoorLocation.Z;
	Owner->SetActorLocation(finalLocation);
}

void UOpenDoor::CloseDoor()
{

}

