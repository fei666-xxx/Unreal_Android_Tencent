// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CollectActor.h"
#include "Core.h"
#include "BatteryCollect.generated.h"

/**
 * 
 */
UCLASS()
class ANDROIDTEST_API ABatteryCollect : public ACollectActor
{
	GENERATED_BODY()

public:
	ABatteryCollect();

	void WasCollected_Implementation() override;

	float GetPower();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Power", meta=(BlueprintProtected="true"))
	float BatteryPower;
};
