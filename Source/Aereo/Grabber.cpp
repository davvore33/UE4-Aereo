#include <kmessagewidget.h>
#include "Aereo.h"
#include "Grabber.h"
// Sets default values for this component's properties
UGrabber::UGrabber() {
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}

/// Called when the game starts
void UGrabber::BeginPlay() {
	Super::BeginPlay();
    FindPhysicsComponent();
    SetupInputComponent();
}

void UGrabber::FindPhysicsComponent() {
    PhysicsHandler = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
    if (!PhysicsHandler) {
        UE_LOG(LogTemp, Error, TEXT("%s doesn't have any PhysicsHandler"), *GetOwner()->GetName());
    }
}

void UGrabber::Grab(){
    UE_LOG(LogTemp, Warning, TEXT("Se continui a premermi così mi eccito"));
//    FHitResult HitRes = HittingSomething();
}

void UGrabber::Release(){
    UE_LOG(LogTemp, Warning, TEXT("Se continui a lasciarmi così mi eccito"));
}

/// Called every frame
void UGrabber::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) {
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
    HittingSomething();
    //TODO: move the handled object
}

FHitResult UGrabber::HittingSomething() {// Get player view point this tick
    FVector POVpos;
    FRotator POVangle;
    GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT POVpos,
		OUT POVangle
	);

    FVector LineTraceStart = POVpos;            //that's useless, just for easier reading
    FVector LineTraceEnd = LineTraceStart + POVangle.Vector() * Reach;

    FHitResult OutHit ;

    FCollisionQueryParams TraceParam(FName(TEXT("")), 0, GetOwner());

    GetWorld()->LineTraceSingleByObjectType(OUT OutHit, LineTraceStart, LineTraceEnd,
                                            FCollisionObjectQueryParams(ECC_PhysicsBody), TraceParam);
    return OutHit;
//    AActor *Hitted = OutHit.GetActor();
//    if(Hitted) {
//        FString AName = Hitted->GetName();
//        UE_LOG(LogTemp, Warning, TEXT("%s hitted"), *AName);
//    }
}

void UGrabber::SetupInputComponent() {

    InputContoller = GetOwner()->FindComponentByClass<UInputComponent>();
    if(InputContoller)
    {
        InputContoller->BindAction("Grab",IE_Pressed,this, &UGrabber::Grab);
        InputContoller->BindAction("Grab",IE_Released,this, &UGrabber::Release);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("%s doesn't have any InputContoller"), *GetOwner()->GetName());
    }

}

