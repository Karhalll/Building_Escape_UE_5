// Copyright Martin Fucik 2021

#include "OpenDoor.h"
#include "GameFramework/Actor.h"

UOpenDoor::UOpenDoor()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

    TargetYaw += GetOwner()->GetActorRotation().Yaw;
}

void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    UE_LOG(LogTemp, Display, TEXT("Current Yaw is: %f"), GetOwner()->GetActorRotation().Yaw);

    float CurrentYaw = GetOwner()->GetActorRotation().Yaw;
    FRotator OpenDoor(0.f, TargetYaw, 0.f);
    OpenDoor.Yaw = FMath::FInterpTo(CurrentYaw, TargetYaw, DeltaTime, 1.f);
    GetOwner()->SetActorRotation(OpenDoor);
}