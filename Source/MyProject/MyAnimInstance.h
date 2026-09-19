#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyAnimInstance.generated.h"

UCLASS()
class MYPROJECT_API UMyAnimInstance : public UAnimInstance
{
    GENERATED_BODY()

public:

    virtual void NativeUpdateAnimation(float DeltaSeconds) override;

    UPROPERTY(BlueprintReadOnly, Category = "Movement")
    float Speed;

    UPROPERTY(BlueprintReadOnly, Category = "Combat")
    bool IsAiming;

    UPROPERTY(BlueprintReadOnly, Category = "Combat")
    bool IsPistolEquipped;
};
