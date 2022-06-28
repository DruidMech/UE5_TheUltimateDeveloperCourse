// Fill out your copyright notice in the Description page of Project Settings.


#include "Breakable/BreakableActor.h"
#include "GeometryCollection/GeometryCollectionComponent.h"
#include "Items/Treasure.h"
#include "Components/CapsuleComponent.h"

ABreakableActor::ABreakableActor()
{
	PrimaryActorTick.bCanEverTick = false;

	GeometryCollection = CreateDefaultSubobject<UGeometryCollectionComponent>(TEXT("GeometryCollection"));
	SetRootComponent(GeometryCollection);
	GeometryCollection->SetGenerateOverlapEvents(true);
	GeometryCollection->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
	GeometryCollection->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	Capsule->SetupAttachment(GetRootComponent());
	Capsule->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	Capsule->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Block);
}

void ABreakableActor::BeginPlay()
{
	Super::BeginPlay();

}

void ABreakableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABreakableActor::GetHit_Implementation(const FVector& ImpactPoint, AActor* Hitter)
{
	if (bBroken) return;
	bBroken = true;
	UWorld* World = GetWorld();
	if (World && TreasureClasses.Num() > 0)
	{
		FVector Location = GetActorLocation();
		Location.Z += 75.f;

		const int32 Selection = FMath::RandRange(0, TreasureClasses.Num() - 1);
		World->SpawnActor<ATreasure>(TreasureClasses[Selection], Location, GetActorRotation());
	}
}

