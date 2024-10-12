// Fill out your copyright notice in the Description page of Project Settings.


#include "Movement.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
AMovement::AMovement()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	JumpCount = 0;
	MaxJumps = 2;

}

// Called when the game starts or when spawned
void AMovement::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMovement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMovement::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMovement::DoubleJump);

}

void AMovement::DoubleJump()
{
    // Check if we have remaining jumps
    if (JumpCount < MaxJumps)
    {
        ACharacter::LaunchCharacter(FVector(0, 0, GetCharacterMovement()->JumpZVelocity), false, true);
        JumpCount++;
    }
}

// Reset the jump count when the character lands
void AMovement::Landed(const FHitResult& Hit)
{
    Super::Landed(Hit);
    JumpCount = 0;
}

