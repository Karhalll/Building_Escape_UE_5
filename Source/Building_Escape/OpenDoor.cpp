// Copyright Martin Fucik 2021

#include "OpenDoor.h"

#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"

UOpenDoor::UOpenDoor()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

    CloseYaw = GetOwner()->GetActorRotation().Yaw;
    OpenYaw += CloseYaw;

    if (!PressurePlate)
    {
        UE_LOG(LogTemp, Error, TEXT("%s has OpenDoor component but no PressurePlate set!"), *GetOwner()->GetName());
    }

    ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}

void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (PressurePlate && PressurePlate->IsOverlappingActor(ActorThatOpens))
    {
        RotateDoor(OpenYaw, DeltaTime);
    }
    else
    {
        RotateDoor(CloseYaw, DeltaTime);
    }
}

void UOpenDoor::RotateDoor(float TargetYaw, float DeltaTime) const
{
    float CurrentYaw = GetOwner()->GetActorRotation().Yaw;
    FRotator TargetRotation(0.f, 0.f, 0.f);
    TargetRotation.Yaw = FMath::FInterpTo(CurrentYaw, TargetYaw, DeltaTime, 1.f);
    GetOwner()->SetActorRotation(TargetRotation);
}