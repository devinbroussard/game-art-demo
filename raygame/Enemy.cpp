#include "Enemy.h"
#include "FollowComponent.h"
#include "MainScene.h"
#include "EnemyAnimationsComponent.h"
#include <iostream>

int Enemy::m_enemyCount = 0;

Enemy::Enemy(float x, float y, const char* name, float speed,Actor* targetActor) :
	Character::Character(x, y, name, speed)
{
	m_targetActor = targetActor;
	AABBCollider* collider = new AABBCollider(40, 40, this);
	Actor::setCollider(collider);
}

void Enemy::start()
{


	//called start
	Character::start();
	//incruments the enemy count
	m_enemyCount++;

	EnemyAnimationsComponent* enemyAnimationsComponent = new EnemyAnimationsComponent("Sprites/sprites/characters/skeleton.png", "sprites/sprites/characters/skeletonleft.png", 6, 5, 8);
	addComponent(enemyAnimationsComponent);

	//initializes the followComonet and sets the target Actor...
	m_followComponent = new FollowComponent( "Follow Component", m_targetActor);
	//...adds the componet to the enemy
	addComponent(m_followComponent);

	//sets the scale for the componet (sprite)
	getTransform()->setScale({ 2.5, 2.5 });
}

void Enemy::update(float deltaTime)
{
	//DrawRectangleLines((getTransform()->getWorldPosition().x), (getTransform()->getWorldPosition().y), 40, 40, BLACK);

	//allows the for the enmey to move my get the move Componet and setting its velocity and putting in the get mvoe Axis then multipling 
	//... with its speed
	if (getHealthComponent()->getHealth() > 0)
		Character::getMoveComponent()->setVelocity(m_followComponent->getMoveAxis() * Character::getSpeed());
	else getMoveComponent()->setVelocity({ 0, 0 });

	//Then update
	Character::update(deltaTime);
}

void Enemy::onCollision(Actor* other)
{
	if (other->getName() == "Attack")
	{
		getHealthComponent()->takeDamage();
		std::cout << "Collision!" << std::endl;
	}
}
