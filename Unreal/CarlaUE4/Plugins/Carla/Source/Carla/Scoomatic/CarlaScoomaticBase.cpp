// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#include "Carla.h"
#include "Carla/Scoomatic/CarlaScoomaticBase.h"

#include "Components/BoxComponent.h"
#include "Engine/CollisionProfile.h"
#include "PhysXPublic.h"
#include "PhysXVehicleManager.h"

// =============================================================================
// -- Constructor and destructor -----------------------------------------------
// =============================================================================

ACarlaScoomaticBase::ACarlaScoomaticBase(const FObjectInitializer& ObjectInitializer) :
  Super(ObjectInitializer)
{
  ScoomaticBounds = CreateDefaultSubobject<UBoxComponent>(TEXT("ScoomaticBounds"));
  ScoomaticBounds->SetupAttachment(RootComponent);
  ScoomaticBounds->SetHiddenInGame(true);
  ScoomaticBounds->SetCollisionProfileName(UCollisionProfile::NoCollision_ProfileName);
}

ACarlaScoomaticBase::~ACarlaScoomaticBase() {}

void ACarlaScoomaticBase::BeginPlay()
{
  Super::BeginPlay();
}

// =============================================================================
// -- Get functions ------------------------------------------------------------
// =============================================================================

FVector ACarlaScoomaticBase::GetScoomaticOrientation() const
{
  return GetScoomaticTransform().GetRotation().GetForwardVector();
}

FTransform ACarlaScoomaticBase::GetScoomaticBoundingBoxTransform() const
{
  return ScoomaticBounds->GetRelativeTransform();
}

FVector ACarlaScoomaticBase::GetScoomaticBoundingBoxExtent() const
{
  return ScoomaticBounds->GetScaledBoxExtent();
}

// =============================================================================
// -- Set functions ------------------------------------------------------------
// =============================================================================

void ACarlaScoomaticBase::FlushScoomaticControl()
{
  VelocityLeft = InputControl.Control.LeftVelocity;
  VelocityRight = InputControl.Control.RightVelocity;
  LastAppliedControl = InputControl.Control;
  InputControl.Priority = EScoomaticInputPriority::INVALID;
}

void ACarlaScoomaticBase::SetLeftVelocity(const float Value)
{
  FScoomaticControl Control = InputControl.Control;
  Control.LeftVelocity = Value;
  ApplyScoomaticControl(Control, EScoomaticInputPriority::User);
}

void ACarlaScoomaticBase::SetRightVelocity(const float Value)
{
  FScoomaticControl Control = InputControl.Control;
  Control.RightVelocity = Value;
  ApplyScoomaticControl(Control, EScoomaticInputPriority::User);
}
