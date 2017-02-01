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

void UGrabber::SetupInputComponent() {

    InputContoller = GetOwner()->FindComponentByClass<UInputComponent>();
    if(InputContoller)
    {
        InputContoller->BindAction("Grab",IE_Pressed,this, &UGrabber::Grab);
        InputContoller->BindAction("Grab",IE_Released,this, &UGrabber::Release);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("%s doesn't have any InputController"), *GetOwner()->GetName());
    }

}

/// Called every frame
void UGrabber::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) {
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
    if (!PhysicsHandler) { return; }
    if(PhysicsHandler->GrabbedComponent){
        PhysicsHandler->SetTargetLocation(GetTheEndReachLine());
    }

}

FVector UGrabber::GetTheEndReachLine() const {
    FVector POVpos;
    FRotator POVangle;
    GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
            OUT POVpos,
            OUT POVangle
    );
    return POVpos + POVangle.Vector() * Reach;
}

FVector UGrabber::GetTheStartReachLine() const {
    FVector POVpos;
    FRotator POVangle;
    GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
            OUT POVpos,
            OUT POVangle
    );
    return POVpos;
}

void UGrabber::Grab(){
    UE_LOG(LogTemp, Warning, TEXT("Se continui a premermi cosi mi eccito"));
    auto HitRes = GetFirstPhysicsBodyInReach();
    UPrimitiveComponent *hittedComponent = HitRes.GetComponent();
    AActor* hittedActor = HitRes.GetActor();
    if (!PhysicsHandler) {return;}
    if(hittedActor != nullptr) {
        PhysicsHandler->GrabComponentAtLocation(
                hittedComponent,
                NAME_None,
                hittedComponent->GetOwner()->GetActorLocation());
    }
}

void UGrabber::Release(){
    UE_LOG(LogTemp, Warning, TEXT("Se continui a lasciarmi cosi mi eccito"));
    if (!PhysicsHandler) { return;}
    PhysicsHandler->ReleaseComponent();
}

const FHitResult UGrabber::GetFirstPhysicsBodyInReach() {// Get player view point this tick

    FHitResult OutHit ;

    FCollisionQueryParams TraceParam(FName(TEXT("")), 0, GetOwner());

    GetWorld()->LineTraceSingleByObjectType(
            OUT OutHit,
            GetTheStartReachLine(),
            GetTheEndReachLine(),
            FCollisionObjectQueryParams(ECC_PhysicsBody),
            TraceParam);

    AActor *Hitted = OutHit.GetActor();
    if(Hitted) {
        FString AName = Hitted->GetName();
        UE_LOG(LogTemp, Warning, TEXT("%s hitted"), *AName);
    }
    return OutHit;
}
