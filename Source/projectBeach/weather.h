// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/DirectionalLightComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Sound/SoundCue.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"
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

	/*UPROPERTY(EditAnywhere)
		UDirectionalLightComponent* directionalLightComponent;

	UPROPERTY(EditAnywhere)
		float LightSpeed;*/
	
	UAudioComponent* AudioManager;
	FTimerHandle TimerHandle_TimeCount;

	//Rain
	UPROPERTY(EditAnywhere)
		float RainLevel;   //雨量 0到1的值
	UPROPERTY(EditAnywhere)
		USoundCue* Sound_Rain;   //雨量 0到1的值


	UPROPERTY(EditAnywhere)
		UParticleSystemComponent* P_Rain;   //雨的粒子系统

	UPROPERTY(EditAnywhere)  //蓝图用 是否可以下雨
		bool FCanRain;
	/*
		控制下雨 
		params:     CanRain：是否可以下雨
					BuferTime：缓冲时间
	*/

	void RainController(bool CanRain, float BuferTime);  

	void TimeControl();


	

};
