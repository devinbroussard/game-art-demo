#include "Enemy.h"
#include "FollowComponent.h"
#include "EnemySpriteComponent.h"
#include "MainScene.h"

int Enemy::m_enemyCount = 0;

Enemy::Enemy(float x, float y, const char* name, float speed,Actor* targetActor) :
	Character::Character(x, y, name, speed)
{
	m_targetActor = targetActor;
	AABBCollider* collider = new AABBCollider(8, 6, this);
	Actor::setCollider(collider);
}

void Enemy::start()
{
	//called start
	Character::start();
	//incruments the enemy count
	m_enemyCount++;
	//initializes the followComonet and sets the target Actor...
	m_followComponent = new FollowComponent( "Follow Component", m_targetActor);
	//...adds the componet to the enemy
	addComponent(m_followComponent);
	//Initializes the enemySpriteComponet
	EnemySpriteComponent* enemySpriteComponent = new EnemySpriteComponent();
	//adds the enmeySprite to the enemy
	addComponent(enemySpriteComponent);
	//sets the scale for the componet (sprite)
	getTransform()->setScale({ 2.5, 2.5 });
}

void Enemy::update(float deltaTime)
{
	//allows the for the enmey to move my get the move Componet and setting its velocity and putting in the get mvoe Axis then multipling 
	//... with its speed
	Character::getMoveComponent()->setVelocity(m_followComponent->getMoveAxis() * Character::getSpeed());
	//Then update
	Character::update(deltaTime);
}
