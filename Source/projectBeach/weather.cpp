// Fill out your copyright notice in the Description page of Project Settings.


#include "weather.h"

// Sets default values
Aweather::Aweather()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	//directionalLightComponent = CreateDefaultSubobject<UDirectionalLightComponent>(TEXT("LightSource"));
	//directionalLightComponent->SetMobility(EComponentMobility::Movable);  
	//directionalLightComponent->AttachTo(RootComponent);
	

	FCanRain = true;
	AudioManager = nullptr;
	//粒子材料
	P_Rain = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("P_Rain"));
	P_Rain->SetupAttachment(RootComponent);

	ConstructorHelpers::FObjectFinder<UParticleSystem>myParticle(TEXT("ParticleSystem'/Game/assert/weather/P_Rain.P_Rain'"));
	if (myParticle.Succeeded())
	{
		P_Rain->SetTemplate(myParticle.Object);//添加粒子资源
	}
	P_Rain->SetActive(false);


	//
	ConstructorHelpers::FObjectFinder<USoundCue>mySound(TEXT("SoundCue'/Game/assert/weather/Sound_Rain_Cue.Sound_Rain_Cue'"));
	Sound_Rain = mySound.Object;




	//LightSource = directionalLightComponent;
	//LightSpeed = 20.0f;

}

// Called when the game starts or when spawned
void Aweather::BeginPlay()
{
	Super::BeginPlay();
	RainController(FCanRain, 0.4);
	GetWorldTimerManager().SetTimer(TimerHandle_TimeCount, this, &Aweather::TimeControl, 4.0f, true, 4.0f);
	
}

// Called every frame
void Aweather::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}
void Aweather::TimeControl()
{
	RainController(!FCanRain, 0.4);
}

void Aweather::RainController(bool CanRain, float BuferTime)
{
	if (CanRain)
	{ 
		P_Rain->SetActive(true);
		if (Sound_Rain)
		{
			AudioManager = UGameplayStatics::SpawnSoundAttached(Sound_Rain, P_Rain);
		}
	}
	else
	{ 
		P_Rain->SetActive(false);
		if (AudioManager)
		{
			AudioManager->Stop();
		}
	}
	FCanRain = !FCanRain;
}

