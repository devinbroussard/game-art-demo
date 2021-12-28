#include "MeleeSwingComponent.h"
#include "MeleeWeaponActor.h"
#include "Transform2D.h"

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
	m_swingTimer += deltaTime;

	if (getMeleeWeapon()->getSwingInput() && m_swingTimer > m_swingCooldown)
		m_swingWeapon = true;
	if (m_swingTimer > m_swingDuration)
	{
		m_swingTimer = 0;
		m_swingWeapon = false;
		getMeleeWeapon()->getTransform()->setRotation(3.14);
	}

	if (m_swingWeapon)
		swingWeapon();

}

void MeleeSwingComponent::swingWeapon()
{
	//if (m_swingTimer > m_swingDuration)
	//{
 //		m_swingWeapon = false;
	//	return;
	//}

	getMeleeWeapon()->getTransform()->rotate(0.01);
}
