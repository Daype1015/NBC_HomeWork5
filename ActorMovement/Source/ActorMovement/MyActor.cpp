// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Engine/Engine.h"

// Sets default values
AMyActor::AMyActor() 
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector(0, 50, 50));
	StartLocation = GetActorLocation();
	Move();
	Turn();
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor::Move()
{
	FVector RandomVector;
	for (int i = 0; i < 10; ++i)
	{
		RandomVector.X = FMath::FRandRange(0.f, 1000.0f);
		RandomVector.Y = FMath::FRandRange(50.f, 1000.0f);
		RandomVector.Z = FMath::FRandRange(50.f, 1000.0f);
		SetActorLocation(RandomVector);
		MoveDistance += FVector::Distance(StartLocation, RandomVector);
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 8.0f, FColor::Black, GetActorLocation().ToString());
		}
		IsEvent = FMath::RandBool();
		if (IsEvent == true)
		{
			FireEvent();
		}
	}
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 8.0f, FColor::Green, FString::Printf(TEXT("event: %d"), EventTime));
		GEngine->AddOnScreenDebugMessage(-1, 8.0f, FColor::White, FString::Printf(TEXT("All of Distance is : %f"), MoveDistance));
	}
}

void AMyActor::Turn()
{
	FRotator RandomRotate;
	for (int i = 0; i < 10; ++i)
	{
		RandomRotate.Pitch = FMath::FRandRange(0.0f, 360.f); 
		RandomRotate.Yaw = FMath::FRandRange(0.0f, 360.f);
		RandomRotate.Roll = FMath::FRandRange(0.0f, 360.f);
		SetActorRotation(RandomRotate);
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, GetActorRotation().ToString());
		}
	}
}

void AMyActor::FireEvent()
{
	EventTime += 1;
}

