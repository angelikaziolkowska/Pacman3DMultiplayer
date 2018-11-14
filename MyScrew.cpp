// Fill out your copyright notice in the Description page of Project Settings.

#include "MyScrew.h"
#include "Classes/Components/BoxComponent.h"


// Sets default values
AMyScrew::AMyScrew()
{
 	// Set this actor to call Tick() every frame
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("MyRoot"));
	RootComponent = Root;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("MyMesh");
	Mesh->AttachToComponent(Root, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("MyBox"));
	Box->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
	Box->bGenerateOverlapEvents = true;
	Box->OnComponentBeginOverlap.AddDynamic(this, &AMyScrew::OnPlayerEnterBox);
	Box->AttachToComponent(Root, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
}

// Called when the game starts or when spawned
void AMyScrew::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyScrew::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyScrew::OnPlayerEnterBox(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	Destroy();
}

