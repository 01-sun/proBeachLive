// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/DirectionalLightComponent.h"
#include "weather.generated.h"

UCLASS()
class PROJECTBEACH_API Aweather : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Aweather();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		UDirectionalLightComponent* directionalLightComponent;

	UPROPERTY(EditAnywhere)
		float LightSpeed;

	UPROPERTY(EditAnywhere, Category = "Sky Sphere")
		TSubclassOf<AActor> SkySphere;

};
