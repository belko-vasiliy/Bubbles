// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BubbleFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class BUBBLES_API UBubbleFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, Category = "Actor")
	static void SortByScale(TArray<AActor*> InActors, bool OnlyBiggestActors, TArray<AActor*> &OutActors);

	UFUNCTION(BlueprintCallable, Category = "Actor")
	static void SortByDistance(TArray<AActor*> InActors, AActor* Target, TArray<AActor*> &OutActors);

	UFUNCTION(BlueprintPure, Category = "SceneComponent")
	static float GetComponentScreenSize(const APlayerController* Player, const USceneComponent* Component, bool PlayerViewportRelative = false);

	UFUNCTION(BlueprintPure, BlueprintCallable, Category = "CommonUtilsFunctionLibrary")
	static bool RunningInPIE();

};
