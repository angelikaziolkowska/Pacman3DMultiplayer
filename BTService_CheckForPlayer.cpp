// Angelika Ziolkowska

#include "BTService_CheckForPlayer.h"
#include "PacmanCppProject.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "PacmanCppProjectCharacter.h"
#include "GhostAI.h"
#include "GhostCharacter.h"

UBTService_CheckForPlayer::UBTService_CheckForPlayer()
{
	bCreateNodeInstance = true;
}

void UBTService_CheckForPlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	AGhostAI *GhostPC = Cast<AGhostAI>(OwnerComp.GetAIOwner());

	if (GhostPC)
	{
		APacmanCppProjectCharacter *Enemy = Cast<APacmanCppProjectCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());

		if (Enemy)
		{
			OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(GhostPC->GhostKeyID, Enemy);
			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, "ENEMY IS HERE!");
		}
	}
}
