// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "tableMoves.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))

class AEREO_API UtableMoves : public UActorComponent {
    GENERATED_BODY()

public:
    // Sets default values for this component's properties
    UtableMoves();

    // Called when the game starts
    virtual void BeginPlay() override;

    // Called every frame
    virtual void
    TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;


};
