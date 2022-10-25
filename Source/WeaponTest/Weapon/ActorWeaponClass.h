// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorWeaponClass.generated.h"

UCLASS()
class WEAPONTEST_API AActorWeaponClass : public AActor
{
	GENERATED_BODY()
	
public:	
	AActorWeaponClass();
	

protected:
	virtual void BeginPlay() override;




};
