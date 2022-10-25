// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorWeaponClass.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FShootDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FReloadingDelegate);

UCLASS(HideCategories=("Rendering","Replication","Collision","Input","Actor","LOD","Cooking"))
class WEAPONTEST_API AActorWeaponClass : public AActor
{
	GENERATED_BODY()
	
#pragma region Default

public:	
	AActorWeaponClass();
	

protected:
	virtual void BeginPlay() override;

#pragma endregion

#pragma region Action

public:
	UFUNCTION(BlueprintCallable, Category = "Weapon Action")
	void Shoot();
	UFUNCTION(BlueprintCallable, Category = "Weapon Action")
	void Reloading();

	UFUNCTION(BlueprintCallable, Category = "Weapon Ammo Action")
	float GetCurrentAmmo();

#pragma endregion

#pragma region Variables

private:
	UPROPERTY(meta=(ClampMin=0))
	float CurrentAmmo{0};
	UPROPERTY(meta=(ClampMax=20))
	float MaxAmmo {20};
	UPROPERTY();
	float AmmoToLose{1};

	UPROPERTY()
	bool isEmpty{false};

	UPROPERTY()
	FShootDelegate ShootDelegate;

	UPROPERTY()
	FReloadingDelegate ReloadingDelegate;

#pragma endregion

#pragma region WeaponComponents

	UPROPERTY()
	USceneComponent* SceneRootComponent;

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* WeaponMesh;

#pragma endregion
	

};
