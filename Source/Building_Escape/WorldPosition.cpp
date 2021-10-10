// Fill out your copyright notice in the Description page of Project Settings.

#include "WorldPosition.h"
#include "GameFramework/Actor.h"

UWorldPosition::UWorldPosition()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UWorldPosition::BeginPlay()
{
	Super::BeginPlay();

    // FString Log = TEXT("Hello!");
    // FString* PtrLog = &Log;

    // Log.Len();

    // (*PtrLog).Len();
    // PtrLog->Len();

	// UE_LOG(LogTemp, Warning, TEXT("%s"), **PtrLog);

    FString ObjectName = GetOwner()->GetName();
    FString ObjectPosition = GetOwner()->GetActorLocation().ToString();
    UE_LOG(LogTemp, Warning, TEXT("World Position.cpp here. I'am attached to %s Actor that is on position: %s."), *ObjectName, *ObjectPosition);
}

void UWorldPosition::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}