// Fill out your copyright notice in the Description page of Project Settings.


#include "BubbleFunctionLibrary.h"

void UBubbleFunctionLibrary::SortByScale(TArray<AActor*> InActors, bool OnlyBiggestActors, TArray<AActor*> &OutActors)
{
	InActors.Sort([](const AActor& A, const AActor& B)
		{
			const float ScaleA = A.GetActorScale3D().X;
			const float ScaleB = B.GetActorScale3D().X;
			return ScaleA > ScaleB;
		});
	if (OnlyBiggestActors)
	{
		int Length = InActors.Num() - 1;
		if (InActors.IsValidIndex(0))
		{
			float BiggestScale = InActors[0]->GetActorScale3D().X;
			for (int i = 0; i <= Length; i++)
			{
				if (BiggestScale <= InActors[i]->GetActorScale3D().X)
				{
					OutActors.Add(InActors[i]);
				}
				else
				{
					break;
				}
			}
		}
	}
	else
	{
		OutActors = InActors;
	}
		
}

void UBubbleFunctionLibrary::SortByDistance(TArray<AActor*> InActors, AActor* Target, TArray<AActor*>& OutActors)
{
	FVector SourceLocation = Target->GetActorLocation();
	InActors.Sort([SourceLocation](const AActor& A, const AActor& B)
		{
			const float DistanceA = FVector::DistSquared(SourceLocation, A.GetActorLocation());
			const float DistanceB = FVector::DistSquared(SourceLocation, B.GetActorLocation());
			return DistanceA < DistanceB;
		});
	OutActors = InActors;
}


float UBubbleFunctionLibrary::GetComponentScreenSize(const APlayerController* Player, const USceneComponent* Component, bool PlayerViewportRelative)
{
	FVector OriginWorldPosition = Component->Bounds.Origin;
	FVector CornerWorldPosition = FVector(Component->Bounds.Origin + Component->Bounds.BoxExtent);
	int32 SizeX, SizeY;
	Player->GetViewportSize(SizeX, SizeY);
	FVector2D ViewportSize = FVector2D(float(SizeX), float(SizeY));

	FVector2D OriginScreenPosition;
	FVector2D CornerScreenPosition;


	if (Player->ProjectWorldLocationToScreen(OriginWorldPosition, OriginScreenPosition, PlayerViewportRelative))
	{
		if (Player->ProjectWorldLocationToScreen(CornerWorldPosition, CornerScreenPosition, PlayerViewportRelative))
		{		
			FVector2D ScreenSize = FVector2D(FVector2D(CornerScreenPosition - OriginScreenPosition) / ViewportSize);
			return ScreenSize.Size();
		}
	}
	return 0.0;
}

bool UBubbleFunctionLibrary::RunningInPIE()
{
#if WITH_EDITOR
	return true;
#else
	return false;
#endif
}
//if (GEngine)
//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT(" Corner %s "), *CornerScreenPosition.ToString()));

