#pragma once
#include "Actor.h"
#include <Vector2.h>
class MoveComponent;
class FollowComponet;
#include "HealthComponent.h"

class Character :
	public Actor
{
public:
	Character(float x, float y, const char* name, float speed);
	~Character();

	HealthComponent* getHealthComponent() { return m_healthComponent; }
	void setVelocity(float x, float y);
	float getSpeed() { return m_speed; }
	void setSpeed(float speed) { m_speed = speed; }

	MoveComponent* getMoveComponent() { return m_moveComponent; }


	void start();
	void update(float deltaTime);
	void draw();

private:
	MathLibrary::Vector2 m_velocity;
	MoveComponent* m_moveComponent;
	HealthComponent* m_healthComponent;

	float m_speed;
	float m_firingCooldown;

};


