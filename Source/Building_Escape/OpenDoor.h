// Copyright Martin Fucik 2021

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerBase.h"

#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDING_ESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
    void RotateDoor(float TargetYaw, float DeltaTime) const;

private:

    UPROPERTY(EditAnywhere)
    float OpenYaw = -90.f;

    float CloseYaw;

    UPROPERTY(EditAnywhere)
    ATriggerBase* PressurePlate;

    UPROPERTY(EditAnywhere)
    AActor* ActorThatOpens;

    float DoorLastOpened = 0.f;

    UPROPERTY(EditAnywhere)
    float DoorCloseDelay = 2.f;

    UPROPERTY(EditAnywhere)
    float DoorMovingSpeed = 1.f;
};