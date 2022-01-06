#pragma once
#include "Component.h"
#include "Actor.h"

class HealthComponent :
	public Component
{
public:
	HealthComponent(int maxHealth, Actor* owner);
	~HealthComponent();

	int getHealth() { return m_currentHealth; }
	void setHealth(int health) { m_currentHealth = health; }
	float getTimeSinceDamage(){ return m_timeSinceDamage; }
	float getDamageCooldown() { return m_damageCooldown; }

	void start() override;
	void update(float deltaTime) override;
	void onCollision(Actor* actor) override;

private:
	int m_maxHealth;
	int m_currentHealth;
	float m_damageCooldown;
	float m_timeSinceDamage;
};

