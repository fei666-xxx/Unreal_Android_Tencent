// Fill out your copyright notice in the Description page of Project Settings.


#include "BatteryCollect.h"

ABatteryCollect::ABatteryCollect()
{
	GetMesh()->SetSimulatePhysics(true);
	BatteryPower = 150.f;
}

void ABatteryCollect::WasCollected_Implementation()
{
	Super::WasCollected_Implementation();
	Destroy();
}

float ABatteryCollect::GetPower()
{
	return BatteryPower;
}