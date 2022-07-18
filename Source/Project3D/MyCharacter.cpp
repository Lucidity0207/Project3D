// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    speed = 5;
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    
    PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);
}

void AMyCharacter::MoveForward(float value)
{
    if(Controller != nullptr)
    {
        const FVector Direction = FVector(1.f,0.f,0.f);
        AddMovementInput(Direction, -value*speed);
        
        if(value<0)
        {
            Controller->ClientSetRotation(FRotator(180.f, 0.f, -180.f));
        }
        else
        {
            Controller->ClientSetRotation(FRotator(180.f, 180.f, -180.f));
        }
        
    }
}

void AMyCharacter::MoveRight(float value)
{
    if(Controller != nullptr)
    {
        const FVector Direction = FVector(0.f,1.f,0.f);
        AddMovementInput(Direction, -value*speed);
        
        if(value<0)
        {
            Controller->ClientSetRotation(FRotator(180.f, 90.f, -180.f));
        }
        else
        {
            Controller->ClientSetRotation(FRotator(180.f, -90.f, -180.f));
        }
        
    }
}
