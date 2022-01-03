#include "Enemy.h"

Enemy::Enemy(float x, float y, const char* name, float speed, int maxHealth, Actor* targetActor) :
	Character::Character(x, y, name, speed, maxHealth)
{
	m_targetActor = targetActor;
}

void Enemy::start()
{
	Character::start();
	FollowComponent* followComponent = new FollowComponent( "Follow Component", m_targetActor);
	addComponent(followComponent);

}

void Enemy::update(float deltaTime)
{
	MathLibrary::Vector2 getMoveDiection = (m_targetActor->getTransform()->getWorldPosition());
	getMoveDiection.getNormalized();
	Actor::update(deltaTime);
	
	//allows for movement
	
}
