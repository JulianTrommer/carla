// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#include "Carla.h"
#include "ScoomaticBaseAIController.h"

#include "Scoomatic/CarlaScoomaticBase.h"

#include "EngineUtils.h"
#include "GameFramework/Pawn.h"

// =============================================================================
// -- Constructor and destructor -----------------------------------------------
// =============================================================================

AScoomaticBaseAIController::AScoomaticBaseAIController(const FObjectInitializer &ObjectInitializer)
  : Super(ObjectInitializer)
{
  PrimaryActorTick.bCanEverTick = true;
  PrimaryActorTick.TickGroup = TG_PrePhysics;
}

AScoomaticBaseAIController::~AScoomaticBaseAIController() {}

// =============================================================================
// -- AController --------------------------------------------------------------
// =============================================================================

void AScoomaticBaseAIController::OnPossess(APawn *aPawn)
{
  Super::OnPossess(aPawn);

  if (IsPossessingAScoomatic())
  {
    UE_LOG(LogCarla, Error, TEXT("Controller already possessing a scoomatic!"));
    return;
  }
  Scoomatic = Cast<ACarlaScoomaticBase>(aPawn);
  check(Scoomatic != nullptr);
}

void AScoomaticBaseAIController::OnUnPossess()
{
  Super::OnUnPossess();

  Scoomatic = nullptr;
}

void AScoomaticBaseAIController::Tick(const float DeltaTime)
{
  Super::Tick(DeltaTime);

  if (!IsPossessingAScoomatic())
  {
    return;
  }

  if (bAutopilotEnabled)
  {
    // Autopilot not implemented
  }
  else
  {
    // Scoomatic->ApplyScoomaticControl(FScoomaticControl{}, EScoomaticInputPriority::Relaxation);
  }

  Scoomatic->FlushScoomaticControl();
}
