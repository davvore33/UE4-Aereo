#include "Aereo.h"
#include "AirplaneDoor.h"

#define OUT
// Sets default values for this component's properties
UAirplaneDoor::UAirplaneDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAirplaneDoor::BeginPlay()
{
	Super::BeginPlay();
    Owner = GetOwner();
    if(!Owner){
        UE_LOG(LogTemp, Error, TEXT("This class havn't any Owner"))
    }
    if(!PressurePlate){
        UE_LOG(LogTemp, Error, TEXT("This class havn't any PressurePlate"))
    }
//    UE_LOG(LogTemp, Warning, TEXT("DoorWaitTime is %f"), DoorWaitTime);
}


float UAirplaneDoor::GetMassOfOverlapActor(){
    float TotalMass = 0.f;
    TArray<AActor*> OverlappingActors;
    if(PressurePlate) {
        PressurePlate->GetOverlappingActors(OUT OverlappingActors);
        for (const auto& Actor : OverlappingActors) {
            TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
            UE_LOG(LogTemp, Warning, TEXT("%s on pressure plate"), *Actor->GetName())
        }
    }
    return TotalMass;
}

// Called every frame
void UAirplaneDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
    if (GetMassOfOverlapActor() > TriggerMass)
    {
        UE_LOG(LogTemp, Warning, TEXT("Mass is %f"), GetMassOfOverlapActor());
        OnOpen.Broadcast();
    } else{
        OnClose.Broadcast();
    }

}

