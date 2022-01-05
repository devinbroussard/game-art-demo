#pragma once
#include "Component.h"
#include "Actor.h"

class HealthComponent :
	public Component
{
public:
	//default constructor for the healthComponet
	HealthComponent(int maxHealth, Actor* owner);
	//default deconstructor for the healthComponet
	~HealthComponent();

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

