// Fill out your copyright notice in the Description page of Project Settings.

#include "Meeting.h"
#include "PlayerShoot.h"


// Sets default values for this component's properties
UPlayerShoot::UPlayerShoot()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...

	Red = FLinearColor(0.3f, 0.0f, 0.0f, 1.0); 
	Ultraviolet = FLinearColor(0.3f, 0.0f, 0.3f, 1.0f);
}


// Called when the game starts
void UPlayerShoot::BeginPlay()
{
	Super::BeginPlay();

	isRedLight = true;
	Player = GetWorld()->GetFirstPlayerController()->GetCharacter(); 
	Owner = Cast<ACharacter>(GetOwner()); 
	Owner->InputComponent->BindAction("ShootLight", IE_Pressed, this, &UPlayerShoot::ShootLight);
	Owner->InputComponent->BindAction("ShootLight", IE_Released, this, &UPlayerShoot::NotShootLight);
	Owner->InputComponent->BindAction("SwitchLight", IE_Pressed, this, &UPlayerShoot::SwitchLight);

	SL_Light = GetOwner()->FindComponentByClass<USpotLightComponent>();
	
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
}


// Called every frame
void UPlayerShoot::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UPlayerShoot::ShootLight()
{
	SL_Light->ToggleVisibility(true);

	if (StaticMeshComponent->GetName().Equals("LightBeam"))
	{
		StaticMeshComponent->ToggleVisibility(true); 
	}
}

void UPlayerShoot::NotShootLight()
{
	SL_Light->ToggleVisibility(false);

	if (StaticMeshComponent->GetName().Equals("LightBeam"))
	{
		StaticMeshComponent->ToggleVisibility(false);
	}
}

void UPlayerShoot::SwitchLight()
{
		if (isRedLight)
		{
			if (StaticMeshComponent->GetName().Equals("LightBeam"))
			{
				Mat_LightBeam->SetVectorParameterValue("Color", Ultraviolet);
				StaticMeshComponent->SetMaterial(0, Mat_LightBeam);
			}
			SL_Light->SetLightColor(FLinearColor(Ultraviolet), true);
			isRedLight = false;
		}

		else
		{
			if (StaticMeshComponent->GetName().Equals("LightBeam"))
			{
				Mat_LightBeam->SetVectorParameterValue("Color", Red);
				StaticMeshComponent->SetMaterial(0, Mat_LightBeam);
			}
			SL_Light->SetLightColor(FLinearColor(Red), true);
			isRedLight = true;
		}
}




