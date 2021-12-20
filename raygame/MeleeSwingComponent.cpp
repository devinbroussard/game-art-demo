#include "MeleeSwingComponent.h"
#include "MeleeWeaponActor.h"
#include "Transform2D.h"
#include "Player.h"

MeleeSwingComponent::MeleeSwingComponent()
{
	m_swingTimer = 0;
	m_swingDuration = 1;
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
}
