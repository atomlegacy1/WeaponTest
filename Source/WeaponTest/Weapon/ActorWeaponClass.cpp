// Fill out your copyright notice in the Description page of Project Settings.

#include "ActorWeaponClass.h"
#include "DrawDebugHelpers.h"


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
	BoxCollision->SetCollisionProfileName("Trigger");

}

void AActorWeaponClass::BeginPlay()
{
	Super::BeginPlay();
	CurrentAmmo = MaxAmmo;
	
}
void AActorWeaponClass::Shoot()
{
	if (isEmpty) return;
	if (CurrentAmmo == 1) isEmpty = true;
	
	DrawDebugLine(
		GetWorld(),
		SceneRootComponent->GetComponentLocation(),
		ArrowComponent->GetComponentLocation(),
		FColor(255,0,0),
		false,
		3.0f,
		0,
		20);
	CurrentAmmo -= AmmoToLose ;
}

void AActorWeaponClass::Reloading()
{

	if (!isEmpty) return;
	CurrentAmmo = MaxAmmo;
	
}

int AActorWeaponClass::GetCurrentAmmo()
{
	return CurrentAmmo;
}

int AActorWeaponClass::GetMaxAmmo()
{
	return MaxAmmo;
}




