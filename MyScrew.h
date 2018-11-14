// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyScrew.generated.h"

class UShapeComponent;
UCLASS()
class PACMANCPPPROJECT_API AMyScrew : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyScrew();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	USceneComponent* Root;

	// the static mesh for the screw
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;
	
	UPROPERTY(EditAnywhere)
	UShapeComponent* Box;

	UFUNCTION()
	void OnPlayerEnterBox(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
