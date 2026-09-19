// Fill out your copyright notice in the Description page of Project Settings.


#include "PistolWeapon.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

APistolWeapon::APistolWeapon()
{
    PrimaryActorTick.bCanEverTick = false;

    Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
    RootComponent = Mesh;
}

void APistolWeapon::BeginPlay()
{
    Super::BeginPlay();
}

void APistolWeapon::Fire()
{
    if (!ProjectileClass) return;

    // Get muzzle socket transform
    FVector MuzzleLocation = Mesh->GetSocketLocation("Muzzle");
    FRotator MuzzleRotation = Mesh->GetSocketRotation("Muzzle");

    FActorSpawnParameters Params;
    Params.Owner = this;
    Params.Instigator = GetInstigator();

    // Spawn projectile
    GetWorld()->SpawnActor<AActor>(
        ProjectileClass,
        MuzzleLocation,
        MuzzleRotation,
        Params
    );
}

void APistolWeapon::UpdateAimRotation(FRotator NewRotation)
{
    Mesh->SetWorldRotation(NewRotation);
}

