// Angelika Ziolkowska

#include "BTTask_MoveToPlayer.h"
#include "PacmanCppProject.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "PacmanCppProjectCharacter.h"
#include "GhostCharacter.h"
#include "GhostAI.h"




EBTNodeResult::Type UBTTask_MoveToPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// get controller from AI owner
	AGhostAI *GhostPC = Cast<AGhostAI>(OwnerComp.GetAIOwner());

	// get the character, cast it from the blackboard value inside the owner component which is AI
	APacmanCppProjectCharacter *Enemy = Cast<APacmanCppProjectCharacter>(OwnerComp.GetBlackboardComponent()->GetValue<UBlackboardKeyType_Object>(GhostPC->GhostKeyID));

	// if enemy exist will move to it and return that succeeded
	if (Enemy)
	{
		GhostPC->MoveToActor(Enemy, 20.f, true, true, true, 0, true);
		return EBTNodeResult::Succeeded;
	}
	else
	{
		return EBTNodeResult::Failed;
	}

	EBTNodeResult::Failed;
}