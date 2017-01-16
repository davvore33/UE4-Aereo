

#include "Aereo.h"
#include "AirplaneDoor.h"


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
    ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
    Owner = GetOwner();
    StartRotation = Owner->GetActorRotation();
    OpenTime = .0f;
//    UE_LOG(LogTemp, Warning, TEXT("DoorWaitTime is %f"), DoorWaitTime);
}

void UAirplaneDoor::OpenDoor() const {

    Owner->SetActorRotation(rotation);
}

void UAirplaneDoor::CloseDoor() const {

    Owner->SetActorRotation(StartRotation);
}


// Called every frame
void UAirplaneDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
    if (PressurePlate->IsOverlappingActor(ActorThatOpens))
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

