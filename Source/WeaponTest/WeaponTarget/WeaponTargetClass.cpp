// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponTargetClass.h"
#include "Engine/StaticMesh.h"

AWeaponTargetClass::AWeaponTargetClass()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRootComponent = CreateDefaultSubobject<USceneComponent>(FName("SceneRootComponent"))
	SetRootComponent(SceneRootComponent);

	TargetMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMesh"));
	TargetMesh->SetupAttachment(SceneRootComponent);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(FName("BoxCollision"));
	BoxCollision->SetupAttachment(SceneRootComponent);

}

void AWeaponTargetClass::BeginPlay()
{
	Super::BeginPlay();
	
}


