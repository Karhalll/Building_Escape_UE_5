// Copyright Martin Fucik 2021

#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"

#include "Grabber.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDING_ESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	UGrabber();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;		

protected:
	virtual void BeginPlay() override;	

private:
    float Reach = 100.f;

    UPhysicsHandleComponent* PhysicsHandle = nullptr;
    UInputComponent* InputComponent = nullptr;

    void FindPhysicsHandle();
    void SetupInputComponent();
    void Grab();
    void Release();
    FHitResult GetFirstPhysicsBodyInReach() const;
};