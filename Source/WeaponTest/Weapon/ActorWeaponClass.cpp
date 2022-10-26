// Fill out your copyright notice in the Description page of Project Settings.

#include "ActorWeaponClass.h"
#include "DrawDebugHelpers.h"
#include "WeaponTest/WeaponTestCharacter.h"


AActorWeaponClass::AActorWeaponClass()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRootComponent = CreateDefaultSubobject<USceneComponent>(FName("SceneRootComponent"));
	SetRootComponent(SceneRootComponent);

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("WeaponMeshComponent"));
	WeaponMesh->SetupAttachment(SceneRootComponent);

	ArrowComponent = CreateDefaultSubobject<UArrowComponent>(FName("ArrowComponent"));
	ArrowComponent->SetupAttachment(SceneRootComponent);
	ArrowComponent->SetHiddenInGame(true);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(FName("BoxCollision"));
	BoxCollision->SetupAttachment(SceneRootComponent);
	BoxCollision->SetGenerateOverlapEvents(true);
	
}

void AActorWeaponClass::BeginPlay()
{
	Super::BeginPlay();
	CurrentAmmo = MaxAmmo;
	
}
void AActorWeaponClass::Shoot(FVector LineTraceStart,FVector LineTraceEnd)
{
	if (!isTaken) return;
	if (isEmpty) return;
	if (CurrentAmmo == 1) isEmpty = true;
	
	FHitResult OutHit;
	FCollisionQueryParams CollisionParams;
	bool isHit = ActorLineTraceSingle(OutHit,LineTraceStart,LineTraceEnd,ECC_WorldStatic,CollisionParams);
	
	DrawDebugLine(
		GetWorld(),
		LineTraceStart,
		LineTraceEnd,
		FColor(255,0,0),
		false,
		3.0f,
		0,
		20);
	if (isHit)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1,1.0f,FColor::Red,FString::Printf(TEXT("Component hit: %s"),*OutHit.GetComponent()->GetName()));
		}
	}
	CurrentAmmo -= AmmoToLose ;
}

void AActorWeaponClass::Reloading()
{
	if (!isTaken) return;
	
		CurrentAmmo = MaxAmmo;
		isEmpty = false;
}


int AActorWeaponClass::GetCurrentAmmo()
{
	return CurrentAmmo;
}

int AActorWeaponClass::GetMaxAmmo()
{
	return MaxAmmo;
}

void AActorWeaponClass::SetIsTaken(bool isTakenOption)
{
	isTaken=isTakenOption;
}





