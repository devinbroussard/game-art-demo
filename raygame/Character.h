#pragma once
#include "Actor.h"
#include <Vector2.h>
class HealthComponent;
class MoveComponent;
class FollowComponet;

class Character :
	public Actor
{
public:
	//Made default contructor for the character
	Character(float x, float y, const char* name, float speed, int maxHealth);
	//decontructor for character
	~Character();
	
	void setVelocity(float x, float y);
	MathLibrary::Vector2 getVelocity() { return m_velocity; }
	float getSpeed() { return m_speed; }
	void setSpeed(float speed) { m_speed = speed; }
	bool getIsAttacking() { return m_isAttacking; }

	//made to functions to get the moveComponet and the follow Componet
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

	HealthComponent* m_healthComponent;
	
	bool m_isAttacking;
	float m_speed;
	int m_maxHealth;
	float m_firingCooldown;

};


