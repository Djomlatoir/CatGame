// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Movement.generated.h"

UCLASS()
class CATGAME_API AMovement : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMovement();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Tracks the number of jumps performed
	int JumpCount;

	// Maximum number of jumps allowed (1 = regular jump, 2 = double jump)
	int MaxJumps;

	// Handles the double jump logic
	void DoubleJump();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Override the Jump function
	virtual void Landed(const FHitResult& Hit) override;

};
