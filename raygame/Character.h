#pragma once
#include "Actor.h"
#include <Vector2.h>
class HealthComponent;
class MoveComponent;
class FollowComponet;
#include "HealthComponent.h"
#include "AttackComponent.h"

class Character :
	public Actor
{
public:
	Character(float x, float y, const char* name, float speed);
	//decontructor for character
	~Character();

	HealthComponent* getHealthComponent() { return m_healthComponent; }
	float getSpeed() { return m_speed; }
	void setSpeed(float speed) { m_speed = speed; }
	bool getIsAttacking() { return m_attackComponent->getIsAttacking(); }
	void setAttacking(bool value) { m_attackComponent->setIsAttacking(value); }


	//made to functions to get the moveComponet and the follow Componet
	MoveComponent* getMoveComponent() { return m_moveComponent; }


	void start() override;
	void update(float deltaTime) override;
	void draw() override;

private:
	MathLibrary::Vector2 m_velocity;
	MoveComponent* m_moveComponent;
	HealthComponent* m_healthComponent;
	AttackComponent* m_attackComponent;
	
	float m_speed;
	float m_firingCooldown;

};


