#pragma once
#include "Component.h"
#include "Actor.h"

class HealthComponent :
	public Component
{
public:
	HealthComponent(int maxHealth);
	~HealthComponent();

	void takeDamage();
	int getHealth() { return m_currentHealth; }
	void setHealth(int health) { m_currentHealth = health; }
	float getTimeSinceDamage(){ return m_timeSinceDamage; }
	float getDamageCooldown() { return m_damageCooldown; }

	//called start
	void start() override;
	//called update
	void update(float deltaTime) override;
	//is called when a collision happens
	void onCollision(Actor* actor) override;

private:
	int m_maxHealth;
	int m_currentHealth;
	float m_damageCooldown;
	float m_timeSinceDamage;
};

