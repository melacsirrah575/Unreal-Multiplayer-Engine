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

public:
	AMovingPlatform();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere)
	float mMoveSpeed = 20.0;

	// MakeEditWidget creates a gizmo in editor we can move around
	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
	FVector mTargetLocation;

	FVector mGlobalTargetLocation;
	FVector mGlobalStartLocation;
};
