// Fill out your copyright notice in the Description page of Project Settings.

#include "Meeting.h"
#include "AI_Movement.h"


// Sets default values for this component's properties
UAI_Movement::UAI_Movement()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	UAI_Movement::ComponentTags.Add(FName("AI_Movement"));
	// ...
}


// Called when the game starts
void UAI_Movement::BeginPlay()
{
	Super::BeginPlay();
	targetIndex = 0;

	IsGrow = false;

	OriScale = GetOwner()->GetActorScale();
	///curScale = ;
	// ...

}


// Called every frame
void UAI_Movement::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (FVector::Dist(target[targetIndex]->GetActorLocation(), GetOwner()->GetActorLocation()) > 200.0f)
	{
		MoveToward(target[targetIndex]->GetActorLocation());
		//UE_LOG(LogTemp, Warning, TEXT("AI moveable"));
	}
	else
	{
		velocity = FVector::ZeroVector;
		targetIndex++;

		if (targetIndex > 2)
		{
			targetIndex = 0;
		}
		//UE_LOG(LogTemp, Warning, TEXT("AI Unmoveable"));
	}

	/// been hit by laser
	if (IsGrow == true)
	{
		if (LightPara <= 5.f && LightPara >= -5.f)
		{
			GetOwner()->SetActorScale3D(FVector(OriScale.X * (1.f + (LightPara / 5.f)), OriScale.Y * (1.f + (LightPara / 5.f)), OriScale.Z * (1.f + (LightPara / 5.f))));
			
			UE_LOG(LogTemp, Warning, TEXT("AI scale x: %f"), GetOwner()->GetActorScale().X);
		}

		IsGrow = false;
	}

	//UE_LOG(LogTemp, Warning, TEXT("AI location X is %f"), target->GetActorLocation().X);

	// ...
}

void UAI_Movement::MoveToward(FVector targetLocation)
{
	float mag = sqrtf((targetLocation.X * GetOwner()->GetActorLocation().X) + (targetLocation.Y * GetOwner()->GetActorLocation().Y) + (targetLocation.Z * GetOwner()->GetActorLocation().Z));
	FVector desired = targetLocation - GetOwner()->GetActorLocation();
	//desired.GetSafeNormal();
	if (mag != 0)
	{
		desired / mag;
	}
	//UE_LOG(LogTemp, Warning, TEXT("AI desire normal X: %f"), desired.X);
	desired * maxSpeed;

	acceleration = desired - velocity;

	if (acceleration.X > maxForce)
	{
		acceleration.X = maxForce;
	}

	if (acceleration.X < -maxForce)
	{
		acceleration.X = -maxForce;
	}

	if (acceleration.Y > maxForce)
	{
		acceleration.Y = maxForce;
	}

	if (acceleration.Y < -maxForce)
	{
		acceleration.Y = -maxForce;
	}

	if (acceleration.Z > maxForce)
	{
		acceleration.Z = maxForce;
	}

	if (acceleration.Z < -maxForce)
	{
		acceleration.Z = -maxForce;
	}

	velocity += acceleration;

	if (velocity.X > maxSpeed)
	{
		velocity.X = maxSpeed;
	}

	if (velocity.X < -maxSpeed)
	{
		velocity.X = -maxSpeed;
	}

	if (velocity.Y > maxSpeed)
	{
		velocity.Y = maxSpeed;
	}

	if (velocity.Y < -maxSpeed)
	{
		velocity.Y = -maxSpeed;
	}

	if (velocity.Z > maxSpeed)
	{
		velocity.Z = maxSpeed;
	}

	if (velocity.Z < -maxSpeed)
	{
		velocity.Z = -maxSpeed;
	}

	GetOwner()->SetActorLocation(GetOwner()->GetActorLocation() + velocity);



	acceleration = FVector::ZeroVector;

}

void UAI_Movement::Limit(FVector vector, float limit)
{
}

