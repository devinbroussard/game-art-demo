#include "Enemy.h"
#include "FollowComponent.h"
#include "EnemySpriteComponent.h"
#include "MainScene.h"

int Enemy::m_enemyCount = 0;

Enemy::Enemy(float x, float y, const char* name, float speed, int maxHealth, Actor* targetActor) :
	Character::Character(x, y, name, speed, maxHealth)
{
	m_targetActor = targetActor;
	
}

void Enemy::start()
{
	Character::start();
	m_enemyCount++;
	m_followComponent = new FollowComponent( "Follow Component", m_targetActor);
	addComponent(m_followComponent);

	//m_inputComponent = new InputComponent(this);
	//addComponent(m_inputComponent);

	EnemySpriteComponent* enemySpriteComponent = new EnemySpriteComponent();
	addComponent(enemySpriteComponent);
	getTransform()->setScale({ 2.5, 2.5 });
}

void Enemy::update(float deltaTime)
{
	Character::getMoveComponent()->setVelocity(m_followComponent->getMoveAxis() * Character::getSpeed());
	Character::update(deltaTime);
}
