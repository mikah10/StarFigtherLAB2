// Fill out your copyright notice in the Description page of Project Settings.


#include "Paddle.h"
//librerias para el movimiento del paddle
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/StaticMeshComponent.h"

// establecemos valores predeterminados 
APaddle::APaddle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM_Padle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM_Padle"));
	RootComponent = SM_Padle;

	//Damos las propiedades fisicas como gravedad y colision 

	SM_Padle->SetEnableGravity(false);
	SM_Padle->SetConstraintMode(EDOFMode::XZPlane);
	SM_Padle->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SM_Padle->SetCollisionProfileName(TEXT("PhysicsActor"));

	FloatingMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Floating Pawn Movement"));

}

// llama al juego para que comience 
void APaddle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
//movimiento de la nave horizontalmente 
// Called to bind functionality to input
void APaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APaddle::MoveHorizontal(float AxisValue)
{

	AddMovementInput(FVector(AxisValue, 0.0f, 0.0f), 1.0f, false);

}

//movienmieto verticalmente
void APaddle::MoveForward(float AxisValue)
{
	AddMovementInput(FVector( 0.0f, 0.0f, AxisValue), 1.0f, false);
}

