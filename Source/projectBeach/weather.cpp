// Fill out your copyright notice in the Description page of Project Settings.


#include "weather.h"

// Sets default values
Aweather::Aweather()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	directionalLightComponent = CreateDefaultSubobject<UDirectionalLightComponent>(TEXT("LightSource"));
	directionalLightComponent->SetMobility(EComponentMobility::Movable);  //ÒÆ¶¯ÐÔ

	//LightSource = directionalLightComponent;
	LightSpeed = 20.0f;

}

// Called when the game starts or when spawned
void Aweather::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Aweather::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator LightRotate = {0,LightSpeed,0};
	AddActorWorldRotation(LightRotate);
	
	//GetClass()->GetName();
	/*auto SkySphereAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/EngineSky/BP_Sky_Sphere'"));
	SkySphereAsset.*/
}

