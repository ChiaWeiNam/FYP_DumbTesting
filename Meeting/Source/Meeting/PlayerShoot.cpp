// Fill out your copyright notice in the Description page of Project Settings.

#include "Meeting.h"
#include "PlayerShoot.h"
#include "AI_Movement.h"

#define OUT

// Sets default values for this component's properties
UPlayerShoot::UPlayerShoot()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...

	isAiming = false;
	isShoot = false;
	isRedLight = true;

	RedBeam = FLinearColor(0.1f, 0.0f, 0.0f, 1.0f);
	UltravioletBeam = FLinearColor(0.1f, 0.0f, 0.2f, 1.0f);

	RedSpot = FLinearColor(1.0f, 0.0f, 0.0f, 1.0f);
	UltravioletSpot = FLinearColor(1.0f, 0.0f, 1.0f, 1.0f);

	ammoLimit = 0.5f;
	ammoText = ammoLimit * 100;
	endPoint = 370.0f;
}


// Called when the game starts
void UPlayerShoot::BeginPlay()
{
	Super::BeginPlay();

	Owner = Cast<ACharacter>(GetOwner());

	CharacterMesh = Owner->FindComponentByClass<USkeletalMeshComponent>();
	GunMesh = CharacterMesh->GetChildComponent(0);
	LaserSource = GunMesh->GetChildComponent(1);
	LaserSight = Owner->FindComponentByClass<UParticleSystemComponent>();
	LaserSight->SetActive(false, false);

	Owner->InputComponent->BindAction("ShootLight", IE_Pressed, this, &UPlayerShoot::ShootLight);
	Owner->InputComponent->BindAction("ShootLight", IE_Released, this, &UPlayerShoot::NotShootLight);
	Owner->InputComponent->BindAction("SwitchLight", IE_Pressed, this, &UPlayerShoot::SwitchLight);

	SL_Light = Owner->FindComponentByClass<USpotLightComponent>();

	TArray<UStaticMeshComponent*> Components;
	Owner->GetComponents<UStaticMeshComponent>(Components);

	for (int32 i = 0; i < Components.Num(); i++)
	{
		StaticMeshComponent = Components[i];
		StaticMesh = StaticMeshComponent->StaticMesh;
	}

	if (StaticMeshComponent->GetName().Equals("LightBeam"))
	{
		Mat_LightBeam = UMaterialInstanceDynamic::Create(StaticMeshComponent->GetMaterial(0), this);
	}

	lightIntensity = SL_Light->Intensity; 
}


// Called every frame
void UPlayerShoot::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (isAiming == true)
	{
		FRotator rotation = LaserSource->GetComponentRotation();
		FVector start = LaserSource->GetComponentLocation();
		FVector end = start + (LaserSource->GetForwardVector() * 150.0f);

		LaserSight->SetBeamSourcePoint(0, start, 0);
		LaserSight->SetBeamTargetPoint(0, end, 0);
		LaserSight->SetActive(true, false);

		if (isShoot == true)
		{
			LaserSight->SetActive(false, false);

			if (StaticMeshComponent->GetName().Equals("LightBeam"))
			{
				if (ammoLimit <= 0.5f && ammoLimit >= 0.05f)
				{
					ammoLimit -= 0.005f;
					ammoText = ammoLimit * 100;
					if (lightIntensity >= 200.0f)
					{
						lightIntensity -= ammoLimit * 200.0f;
					}

					Mat_LightBeam->SetScalarParameterValue("Opacity", ammoLimit);
					StaticMeshComponent->SetMaterial(0, Mat_LightBeam);
					SL_Light->SetIntensity(lightIntensity);
				}

				if (ammoText == 4)
				{
					ammoText = 0;
				}
			}

			SpotLightLocation = SL_Light->GetComponentLocation();
			SpotLightRotation = SL_Light->GetComponentRotation();

			LineTraceEnd = SpotLightLocation + SpotLightRotation.Vector() * endPoint;
			//DrawDebugLine(GetWorld(), SpotLightLocation, LineTraceEnd, FColor::Cyan, false, 0.0f, 0.0f, 5.0f);

			FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());

			FHitResult Hit;
			GetWorld()->LineTraceSingleByObjectType(OUT Hit, SpotLightLocation, LineTraceEnd, FCollisionObjectQueryParams(ECollisionChannel::ECC_Pawn), TraceParameters);

			AActor* ActorHit = Hit.GetActor();
			if (ActorHit && isRedLight)
			{
				UE_LOG(LogTemp, Error, TEXT("red: %s"), *ActorHit->GetName());

				if (ActorHit->FindComponentByClass<UAI_Movement>())
				{
					ActorHit->FindComponentByClass<UAI_Movement>()->IsGrow = true;
					if (ActorHit->FindComponentByClass<UAI_Movement>()->LightPara <= 5.f)
					{
						ActorHit->FindComponentByClass<UAI_Movement>()->LightPara += 0.01f;
					}
				}
			}

			else if (ActorHit && !isRedLight)
			{
				UE_LOG(LogTemp, Error, TEXT("purple"));
				if (ActorHit->FindComponentByClass<UAI_Movement>())
				{
					ActorHit->FindComponentByClass<UAI_Movement>()->IsGrow = true;
					if (ActorHit->FindComponentByClass<UAI_Movement>()->LightPara >= -5.f)
					{
						ActorHit->FindComponentByClass<UAI_Movement>()->LightPara -= 0.01f;
					}

				}
			}
		}
	}

	else
	{
		LaserSight->SetActive(false, true);

		SL_Light->SetVisibility(false, false);
		if (StaticMeshComponent->GetName().Equals("LightBeam"))
		{
			StaticMeshComponent->SetVisibility(false, false);
		}
		isShoot = false;
	}
}

void UPlayerShoot::ShootLight()
{
	if (isAiming == true)
	{
		isShoot = true;

		SL_Light->SetVisibility(true, false);

		if (StaticMeshComponent->GetName().Equals("LightBeam"))
		{
			StaticMeshComponent->SetVisibility(true, false);
		}
	}
}

void UPlayerShoot::NotShootLight()
{
	if (isAiming == true)
	{
		isShoot = false;

		SL_Light->SetVisibility(false, false);

		if (StaticMeshComponent->GetName().Equals("LightBeam"))
		{
			StaticMeshComponent->SetVisibility(false, false);
		}
	}
}

void UPlayerShoot::SwitchLight()
{
	if (isRedLight)
	{
		if (StaticMeshComponent->GetName().Equals("LightBeam"))
		{
			Mat_LightBeam->SetVectorParameterValue("Color", UltravioletBeam);
			StaticMeshComponent->SetMaterial(0, Mat_LightBeam);
		}
		SL_Light->SetLightColor(FLinearColor(UltravioletSpot), true);
		isRedLight = false;
	}

	else
	{
		if (StaticMeshComponent->GetName().Equals("LightBeam"))
		{
			Mat_LightBeam->SetVectorParameterValue("Color", RedBeam);
			StaticMeshComponent->SetMaterial(0, Mat_LightBeam);
		}
		SL_Light->SetLightColor(FLinearColor(RedSpot), true);
		isRedLight = true;
	}
}