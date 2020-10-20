// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#pragma once

#include <queue>

#include "GameFramework/Controller.h"

#include "Scoomatic/ScoomaticControl.h"

#include "ScoomaticBaseAIController.generated.h"

class ACarlaScoomaticBase;

/// Scoomatic base controller with optional AI.
UCLASS()
class CARLA_API AScoomaticBaseAIController final : public AController
{
  GENERATED_BODY()

  // ===========================================================================
  /// @name Constructor and destructor
  // ===========================================================================
  /// @{

public:

  AScoomaticBaseAIController(const FObjectInitializer &ObjectInitializer);

  ~AScoomaticBaseAIController();

  /// @}
  // ===========================================================================
  /// @name Controller overrides
  // ===========================================================================
  /// @{

public:

  void OnPossess(APawn *aPawn) override;

  void OnUnPossess() override;

  void Tick(float DeltaTime) override;

  /// @}
  // ===========================================================================
  /// @name Possessed scoomatic
  // ===========================================================================
  /// @{

public:

  UFUNCTION(Category = "Scoomatic Base Controller", BlueprintCallable)
  bool IsPossessingAScoomatic() const
  {
    return Scoomatic != nullptr;
  }

  UFUNCTION(Category = "Scoomatic Base Controller", BlueprintCallable)
  ACarlaScoomaticBase *GetPossessedScoomatic()
  {
    return Scoomatic;
  }

  const ACarlaScoomaticBase *GetPossessedScoomatic() const
  {
    return Scoomatic;
  }

  /// @}
  // ===========================================================================
  /// @name Control options
  // ===========================================================================
  /// @{

  UFUNCTION(Category = "Scoomatic Base Controller", BlueprintCallable)
  void SetStickyControl(bool bEnabled)
  {
    bControlIsSticky = bEnabled;
  }


  /// @}
  // ===========================================================================
  /// @name Autopilot
  // ===========================================================================
  /// @{

public:

  UFUNCTION(Category = "Scoomatic Base Controller", BlueprintCallable)
  bool IsAutopilotEnabled() const
  {
    return bAutopilotEnabled;
  }

  /// @}
  // ===========================================================================
  // -- Member variables -------------------------------------------------------
  // ===========================================================================
  /// @{

private:

  UPROPERTY()
  ACarlaScoomaticBase *Scoomatic = nullptr;

  UPROPERTY(VisibleAnywhere)
  bool bAutopilotEnabled = false;

  UPROPERTY(VisibleAnywhere)
  bool bControlIsSticky = true;

};
