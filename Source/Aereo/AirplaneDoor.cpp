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
    StartRotation = Owner->GetActorRotation();
    OpenTime = .0f;
//    UE_LOG(LogTemp, Warning, TEXT("DoorWaitTime is %f"), DoorWaitTime);
}

void UAirplaneDoor::OpenDoor() const {
    if(!Owner){ return;}
    Owner->SetActorRotation(rotation);
}

void UAirplaneDoor::CloseDoor() const {
    if(!Owner){ return;}
    Owner->SetActorRotation(StartRotation);
}

float UAirplaneDoor::GetMassOfOverlapActor(){
    float TotalMass = 80.f;
    TArray<AActor*> OverlappingActors;
    if(PressurePlate) {
        PressurePlate->GetOverlappingActors(OUT OverlappingActors);
        //    for(APhysicsConstraintActor* OverlappingActor : OverlappingActors){
        //        TotalMass += OverlappingActor->Mass
        //    }
    }
    return TotalMass;
}

// Called every frame
void UAirplaneDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
    if (GetMassOfOverlapActor() > 50.f)
    {
        OpenTime = GetWorld()->GetTimeSeconds();
//        UE_LOG(LogTemp, Warning, TEXT("OpenTime is %f"), OpenTime);
        OpenDoor();
    }
    if(OpenTime!=.0f){
        if(DoorWaitTime<GetWorld()->GetTimeSeconds()-OpenTime){
            CloseDoor();
        }
    }

}

