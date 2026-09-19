
#include "MyAnimInstance.h"
#include "GameFramework/Pawn.h"
#include "MyProjectCharacter.h"

void UMyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
    Super::NativeUpdateAnimation(DeltaSeconds);

    APawn* Pawn = TryGetPawnOwner();
    if (!Pawn) return;

    AMyProjectCharacter* Character = Cast<AMyProjectCharacter>(Pawn);
    if (!Character) return;

    Speed = Pawn->GetVelocity().Size();
    IsAiming = Character->IsAiming;
    IsPistolEquipped = Character->IsPistolEquipped;
}
