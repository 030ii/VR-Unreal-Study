// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSProject.h"
#include "FPSCharacter.h"


// Sets default values
AFPSCharacter::AFPSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (GEngine)
	{
		// 5�ʰ� ����� �޽����� ǥ���մϴ�. (ù �μ���) -1 "Key" ���� �� �޽����� ������Ʈ �Ǵ� ���ΰ�ĥ �ʿ䰡 ������ ��Ÿ���ϴ�.
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("We are using FPSCharacter."));
	}
}

// Called every frame
void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// "movement" ���ε� ����
	InputComponent->BindAxis("MoveForward", this, &AFPSCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AFPSCharacter::MoveRight);
}

void AFPSCharacter::MoveForward(float Value)
{
	// ��� ���� �������� �˾Ƴ���, �÷��̾ �� �������� �̵��ϰ��� �Ѵٰ� ����մϴ�.
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);
}

void AFPSCharacter::MoveRight(float Value)
{
	// ��� ���� �������� �˾Ƴ���, �÷��̾ �� �������� �̵��ϰ��� �Ѵٰ� ����մϴ�.
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}