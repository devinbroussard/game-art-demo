#include "Enemy.h"
#include "FollowComponent.h"
#include "MoveComponent.h"

Enemy::Enemy(float x, float y, const char* name, float speed, int maxHealth, Actor* targetActor) :
	Character::Character(x, y, name, speed, maxHealth)
{
	m_targetActor = targetActor;
}

void Enemy::start()
{
	Character::start();
	FollowComponent* followComponent = new FollowComponent(this, "Follow Component", m_targetActor);
	addComponent(followComponent);
}

void Enemy::update(float deltaTime)
{
	Actor::update(deltaTime);
	//allows for movement
	
}
