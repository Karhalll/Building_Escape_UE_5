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
	UOpenDoor();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    float TotalMassOfActors() const;

protected:
	virtual void BeginPlay() override;


private:
    void RotateDoor(float TargetYaw, float MoveSpeed, float DeltaTime) const;

    UPROPERTY(EditAnywhere)
    float MassToOpenDoor = 50.f;

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
    float DoorOpenSpeed = 1.f;

    UPROPERTY(EditAnywhere)
    float DoorCloseSpeed = 1.f;
};