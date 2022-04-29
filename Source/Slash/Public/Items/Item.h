// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class SLASH_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AItem();
	virtual void Tick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;
private:
	UPROPERTY(VisibleAnywhere)
	float RunningTime;

	UPROPERTY(EditAnywhere)
	float Amplitude = 0.25f;

	UPROPERTY(EditAnywhere)
	float TimeConstant = 5.f;
};
