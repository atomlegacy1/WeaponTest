// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "WeaponTargetClass.generated.h"

UCLASS(HideCategories = (""))
class WEAPONTEST_API AWeaponTargetClass : public AActor
{
	GENERATED_BODY()

#pragma region Default

public:	
	AWeaponTargetClass();

protected:
	virtual void BeginPlay() override;

#pragma endregion
#pragma region Components

private:

	UPROPERTY()
	USceneComponent* SceneRootComponent;
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* TargetMesh;
	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* BoxCollision;

#pragma endregion

};
