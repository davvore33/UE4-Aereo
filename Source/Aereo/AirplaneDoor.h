#pragma once

#include "Components/ActorComponent.h"
#include "AirplaneDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);

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
    ///Variables

    UPROPERTY(EditAnywhere)
    ATriggerVolume* PressurePlate = nullptr;

    UPROPERTY(EditAnywhere)
    float TriggerMass = 30.f;

    UPROPERTY(BlueprintAssignable)
    FDoorEvent OnOpen;

    UPROPERTY(BlueprintAssignable)
    FDoorEvent OnClose;

    AActor* Owner = nullptr;

    ///Functions
    float GetMassOfOverlapActor();

};
