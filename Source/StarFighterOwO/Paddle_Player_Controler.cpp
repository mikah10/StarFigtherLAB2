// Fill out your copyright notice in the Description page of Project Settings.


#include "Paddle_Player_Controler.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"
#include "Paddle.h"


APaddle_Player_Controler::APaddle_Player_Controler()
{
}

void APaddle_Player_Controler::BeginPlay()
{
	// codigo para la camara sea la que creamos 
	TArray<AActor*> CameraActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);

	FViewTargetTransitionParams Params;
	SetViewTarget(CameraActors[0], Params);



}
//movimiento del paddle

void APaddle_Player_Controler::SetupInputComponent()
{

	Super::SetupInputComponent();

	EnableInput(this);

	InputComponent->BindAxis("MoveHorizontal", this, &APaddle_Player_Controler::MoveHorizontal);

	InputComponent->BindAxis("MoveForward", this, &APaddle_Player_Controler::MoveForward);
}


//acceso a teclas  para movimiento de paddle horizontalmente

void APaddle_Player_Controler::MoveHorizontal(float AxisValue)
{

	auto MyPawn = Cast<APaddle>(GetPawn());

	if (MyPawn) {

		MyPawn->MoveHorizontal(AxisValue);
	}

}

//movimiento del paddle verticalmente 

void APaddle_Player_Controler::MoveForward(float AxisValue)
{

	auto MyPawn = Cast<APaddle>(GetPawn());
	 
	if (MyPawn) {

		MyPawn->MoveForward(AxisValue);
	}

}
