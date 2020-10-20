// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#pragma once

#include "CarlaScoomaticBaseState.generated.h"

/// State of a ACarlaScoomaticBase, to be displayed in editor for debugging
/// purposes.
UENUM(BlueprintType)
enum class ECarlaScoomaticBaseState : uint8
{
  AutopilotOff UMETA(DisplayName        = "Autopilot Off"),
  FreeDriving UMETA(DisplayName         = "Free driving"),
  FollowingFixedRoute UMETA(DisplayName = "Following fixed route"),
  WaitingForRedLight UMETA(DisplayName  = "Waiting for red light"),
  ObstacleAhead UMETA(DisplayName       = "Obstacle ahead"),
  UNKNOWN UMETA(DisplayName             = "Unknown")
};
