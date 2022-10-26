// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
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
	void Shoot(FVector LineTraceStart,FVector LineTraceEnd);
	UFUNCTION(BlueprintCallable, Category = "Weapon Action")
	void Reloading();

	UFUNCTION(BlueprintCallable, Category = "Weapon Ammo Action")
	int GetCurrentAmmo();
	UFUNCTION(BlueprintCallable, Category = "Weapon Ammo Action")
	int GetMaxAmmo();

	UFUNCTION(BlueprintCallable,Category = "Weapon Action")
	void SetIsTaken(bool isTakenOption);


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
	UPROPERTY();
	bool isTaken{false};
	UPROPERTY()
	bool isCanReload{false};

#pragma endregion

#pragma region WeaponComponents

	UPROPERTY()
	USceneComponent* SceneRootComponent;
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* WeaponMesh;
	UPROPERTY()
	UArrowComponent* ArrowComponent;
	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* BoxCollision;

#pragma endregion
	

};
