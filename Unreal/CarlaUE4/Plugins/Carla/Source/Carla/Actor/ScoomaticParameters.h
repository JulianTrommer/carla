// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#pragma once

#include "Carla/Scoomatic/CarlaScoomaticBase.h"

#include "ScoomaticParameters.generated.h"

USTRUCT(BlueprintType)
struct CARLA_API FScoomaticParameters
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FString Make;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FString Model;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  TSubclassOf<ACarlaScoomaticBase> Class;
};
