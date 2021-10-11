// Copyright Martin Fucik 2021

#include "Grabber.h"

#include "DrawDebugHelpers.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"

#define OUT

UGrabber::UGrabber()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UGrabber::BeginPlay()
{
	Super::BeginPlay();

    FindPhysicsHandle();
    SetupInputComponent();
}

void UGrabber::FindPhysicsHandle()
{
    PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
    if (PhysicsHandle)
    {
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("%s has a Grabber component but no PhysicsHandle attached to it!"), *GetOwner()->GetName());
    }
}

void UGrabber::SetupInputComponent()
{
    InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
    if (InputComponent)
    {
        InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
        InputComponent->BindAction("Grab", IE_Released, this, &UGrabber::Release);
    }
}

void UGrabber::Grab()
{
    UE_LOG(LogTemp, Warning, TEXT("Grab pressed!"));
    GetFirstPhysicsBodyInReach();
}

void UGrabber::Release()
{
    UE_LOG(LogTemp, Warning, TEXT("Grab released!"));
}

void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction); 
}

FHitResult UGrabber::GetFirstPhysicsBodyInReach() const
{
    FVector PlayerViewPointLocation;
    FRotator PlayerViewPointRotation;
    GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
        OUT PlayerViewPointLocation,
        OUT PlayerViewPointRotation
    );

    FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;

    FHitResult Hit;
    FCollisionQueryParams TraceParams(
        FName(TEXT("")),
        false,
        GetOwner()
    );

    GetWorld()->LineTraceSingleByObjectType(
        OUT Hit,
        PlayerViewPointLocation,
        LineTraceEnd,
        FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
        TraceParams
    );

    if (Hit.GetActor())
    {
        UE_LOG(LogTemp, Warning, TEXT("Player aiming at: %s."), *Hit.GetActor()->GetName());
    }

    return Hit;
}