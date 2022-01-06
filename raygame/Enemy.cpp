#include "Enemy.h"
#include "FollowComponent.h"


Enemy::Enemy(float x, float y, const char* name, float speed,Actor* targetActor) :
	Character::Character(x, y, name, speed)
{
	m_targetActor = targetActor;
}

void Enemy::start()
{
	Character::start();
	m_followComponent = new FollowComponent( "Follow Component", m_targetActor);
	addComponent(m_followComponent);
}

void Enemy::update(float deltaTime)
{
	Character::getMoveComponent()->setVelocity(m_followComponent->getMoveAxis() * Character::getSpeed());
	Character::update(deltaTime);
}
