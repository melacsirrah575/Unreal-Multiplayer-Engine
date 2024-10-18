// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
    // Gives us access to dt
    PrimaryActorTick.bCanEverTick = true;

    // Required to set this for any object with movement
    // Can also be changed in the editor
    SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
    Super::BeginPlay();

    // Sets up replication for actor which allows clients to see server-side updates
    if (HasAuthority())
    {
        SetReplicates(true);
        SetReplicateMovement(true);
    }

    // mLocalTargetLocation is in local space due to it being an attached gizmo
    // We need to convert its value from Local space to Global Space
    // We are using TransformPosition instead of TransformVector because we want to update the Translation
    mGlobalStartLocation = GetActorLocation();
    mGlobalTargetLocation = GetTransform().TransformPosition(mTargetLocation);
}

void AMovingPlatform::Tick(float deltaTime)
{
    Super::Tick(deltaTime);

    // Used to determine if we are writing to client or server
    // True = server. False = client
    if (HasAuthority())
    {
        FVector Location = GetActorLocation();
        float JourneyLength = (mGlobalTargetLocation - mGlobalStartLocation).Size();
        float JourneyTravelled = (Location - mGlobalStartLocation).Size();
        if (JourneyTravelled >= JourneyLength)
        {
            FVector Swap = mGlobalStartLocation;
            mGlobalStartLocation = mGlobalTargetLocation;
            mGlobalTargetLocation = Swap;
        }
        FVector Direction = (mGlobalTargetLocation - mGlobalStartLocation).GetSafeNormal();
        Location += mMoveSpeed * deltaTime * Direction;
        SetActorLocation(Location);
    }
}
