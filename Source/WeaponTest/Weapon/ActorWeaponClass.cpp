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

}

void AActorWeaponClass::BeginPlay()
{
	Super::BeginPlay();
	
}
void AActorWeaponClass::Shoot()
{
	if (isEmpty) return;

	
	ShootDelegate.Broadcast();
	DrawDebugLine();
	CurrentAmmo -= AmmoToLose ;
}

void AActorWeaponClass::Reloading()
{
	if (!isEmpty) return;

	ReloadingDelegate.Broadcast();
	CurrentAmmo = MaxAmmo;
	
}

float AActorWeaponClass::GetCurrentAmmo()
{
	return CurrentAmmo;
}



