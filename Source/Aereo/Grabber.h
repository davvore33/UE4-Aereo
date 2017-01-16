

#pragma once

#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class AEREO_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

private:

	///Variables
	// How far ahead of the player can we reach in cm
	UPROPERTY(EditAnywhere)
	float Reach = 100.f;
	UPhysicsHandleComponent* PhysicsHandler = nullptr;
	UInputComponent* InputContoller = nullptr;

	///Methods
	void FindPhysicsComponent();

	void Grab();

	void Release();

    FHitResult HittingSomething();

    void SetupInputComponent();
};
