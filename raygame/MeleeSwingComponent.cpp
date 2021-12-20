#include "MeleeSwingComponent.h"
#include "MeleeWeaponActor.h"
#include "Transform2D.h"
#include "Player.h"

MeleeSwingComponent::MeleeSwingComponent(float swingDuration, float swingCooldown)
{
	m_swingDuration = swingDuration;
	m_swingCooldown = swingCooldown;
}

MeleeSwingComponent::~MeleeSwingComponent()
{
}

void MeleeSwingComponent::start()
{
	Component::start();
}

void MeleeSwingComponent::update(float deltaTime)
{
	if (getMeleeWeapon()->getSwingInput());
}
