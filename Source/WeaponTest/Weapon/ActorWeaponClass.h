// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "ActorWeaponClass.generated.h"

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
	int GetCurrentAmmo();
	UFUNCTION(BlueprintCallable, Category = "Weapon Ammo Action")
	int GetMaxAmmo();

#pragma endregion

#pragma region Variables

private:
	UPROPERTY()
	int CurrentAmmo{0};
	UPROPERTY()
	int MaxAmmo {10};
	UPROPERTY();
	int AmmoToLose{1};

	UPROPERTY()
	bool isEmpty{false};

#pragma endregion

#pragma region WeaponComponents

	UPROPERTY()
	USceneComponent* SceneRootComponent;
	UPROPERTY()
	UStaticMeshComponent* WeaponMesh;
	UPROPERTY()
	UArrowComponent* ArrowComponent;
	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* BoxCollision;


#pragma endregion
	

};
