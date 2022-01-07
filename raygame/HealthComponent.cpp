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
	if (m_timeSinceDamage > m_damageCooldown)
	{
		m_timeSinceDamage = 0;
		m_currentHealth--;
	}
}

void HealthComponent::start()
{
	m_currentHealth = m_maxHealth;
	m_timeSinceDamage = 10;
	Component::start();
}

void HealthComponent::update(float deltaTime)
{
	m_timeSinceDamage += deltaTime;
	Component::update(deltaTime);
}

void HealthComponent::onCollision(Actor* actor)
{
	if (actor->getName() == "Enemy")
	{
		m_currentHealth--;
		m_timeSinceDamage = 0;
	}
}
