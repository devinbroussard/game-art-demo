#pragma once
#include "Actor.h"
#include <Vector2.h>
class MoveComponent;
class FollowComponet;

class Character :
	public Actor
{
public:
	Character(float x, float y, const char* name, float speed, int maxHealth);
	~Character();

	void setVelocity(float x, float y);
	float getSpeed() { return m_speed; }
	void setSpeed(float speed) { m_speed = speed; }

	MoveComponent* getMoveComponent() { return m_moveComponent; }
	FollowComponet* getFollowComponet() { return m_followComponet; }


	void start();
	void update(float deltaTime);
	void draw();

private:
	MathLibrary::Vector2 m_velocity;
	MoveComponent* m_moveComponent;
	FollowComponet* m_followComponet;
	Actor* m_targetActor;

	float m_speed;
	int m_maxHealth;
	float m_firingCooldown;

};


