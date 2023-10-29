// Copyright Epic Games, Inc. All Rights Reserved.

#include "AndroidTestGameMode.h"
#include "AndroidTestCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"

AAndroidTestGameMode::AAndroidTestGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	DecayRate = 0.02f;
}

void AAndroidTestGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AAndroidTestCharacter* MyCharacter = Cast<AAndroidTestCharacter>(UGameplayStatics::GetPlayerPawn(this,0));
	if (MyCharacter && MyCharacter->GetCurrentPower()>0)
	{
		MyCharacter->UpdatePower(-DeltaTime * DecayRate * MyCharacter->GetInitialPower());
	}
}

void AAndroidTestGameMode::BeginPlay()
{
	Super::BeginPlay();
	if (HUDWidgetClass != NULL)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), HUDWidgetClass);
		if (CurrentWidget != NULL)
		{
			CurrentWidget->AddToViewport();
		}
	}
}