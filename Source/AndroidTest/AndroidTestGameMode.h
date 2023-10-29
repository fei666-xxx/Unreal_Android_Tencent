// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AndroidTestGameMode.generated.h"

UCLASS(minimalapi)
class AAndroidTestGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AAndroidTestGameMode();
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Power", meta=(BlueprintProtected="true"))
	float DecayRate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", meta = (BlueprintProtected = "true"))
	TSubclassOf<class UUserWidget>HUDWidgetClass;

	UPROPERTY()
	class UUserWidget* CurrentWidget;
};	



