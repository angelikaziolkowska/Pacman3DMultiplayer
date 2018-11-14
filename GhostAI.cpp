// Fill out your copyright notice in the Description page of Project Settings.

#include "GhostAI.h"
#include "PacmanCppProject.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "GhostCharacter.h"


AGhostAI::AGhostAI()
{
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));

	BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehavorComp"));
}

void AGhostAI::Possess(APawn *InPawn)
{
	Super::Possess(InPawn);

	AGhostCharacter *Char = Cast<AGhostCharacter>(InPawn);

	if (Char && Char->BotBehavior)
	{
		BlackboardComp->InitializeBlackboard(*Char->BotBehavior->BlackboardAsset);

		GhostKeyID = BlackboardComp->GetKeyID("Target");

		BehaviorComp->StartTree(*Char->BotBehavior);
	}
}