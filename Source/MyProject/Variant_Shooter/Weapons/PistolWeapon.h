// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PistolWeapon.generated.h"

UCLASS()
class MYPROJECT_API APistolWeapon : public AActor
{
    GENERATED_BODY()

public:
    APistolWeapon();

    UFUNCTION(BlueprintCallable)
    void Fire();

protected:
    virtual void BeginPlay() override;

public:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    USkeletalMeshComponent* Mesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
    TSubclassOf<AActor> ProjectileClass;

public:
    void UpdateAimRotation(FRotator NewRotation);

};
