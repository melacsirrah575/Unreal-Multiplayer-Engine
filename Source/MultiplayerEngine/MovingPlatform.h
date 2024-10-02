// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 *
 */
UCLASS()
class MULTIPLAYERENGINE_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	int32 myInt = 0;

	UPROPERTY(EditAnywhere)
	float myFloat = 0;
};
