// Angelika Ziolkowska

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTService_CheckForPlayer.generated.h"

/**
 * 
 */
UCLASS()
class PACMANCPPPROJECT_API UBTService_CheckForPlayer : public UBTService
{
	GENERATED_BODY()
	
public:

	UBTService_CheckForPlayer();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	
	
};
