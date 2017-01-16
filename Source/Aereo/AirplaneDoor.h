

#pragma once

#include "Components/ActorComponent.h"
#include "AirplaneDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class AEREO_API UAirplaneDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAirplaneDoor();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

private:
    UPROPERTY(EditAnywhere)
    FRotator rotation;

    UPROPERTY(EditAnywhere)
    ATriggerVolume* PressurePlate;

    UPROPERTY(EditAnywhere)
    float DoorWaitTime;

    AActor* ActorThatOpens = nullptr;
    AActor* Owner = nullptr;
    FRotator StartRotation;
    void OpenDoor() const;
    void CloseDoor() const;

    float OpenTime;

};
