#include "HealthComponent.h"

HealthComponent::HealthComponent(int maxHealth) :
	Component::Component("Health Component")
{
	m_maxHealth = maxHealth;
	m_currentHealth = maxHealth;
	m_damageCooldown = 5;
	m_timeSinceDamage = 0;
}

HealthComponent::~HealthComponent()
{
}

void HealthComponent::takeDamage()
{
	//if the time since damage is greater than the damage cooldown
	if (m_timeSinceDamage > m_damageCooldown)
	{
		//reset the time since damage ...
		m_timeSinceDamage = 0;
		//...decrement health
		m_currentHealth--;
	}
}

void HealthComponent::start()
{
	//sets the curretn health to the max
	m_currentHealth = m_maxHealth;
	//sets the time Since Damage to 10 to not get one shot by enemies
	m_timeSinceDamage = 10;
	Component::start();
}

void HealthComponent::update(float deltaTime)
{
	//adds the deltaTIme to the Time Since Damage
	m_timeSinceDamage += deltaTime;
	Component::update(deltaTime);
}

void HealthComponent::onCollision(Actor* actor)
{
}
