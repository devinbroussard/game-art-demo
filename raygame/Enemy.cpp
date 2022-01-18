#include "Enemy.h"
#include "FollowComponent.h"
#include "MainScene.h"
#include "EnemyAnimationsComponent.h"
#include "HealthDisplay.h"
#include "Engine.h"

int Enemy::m_enemyCount = 0;

Enemy::Enemy(float x, float y, const char* name, float speed,Actor* targetActor) :
	Character::Character(x, y, name, speed)
{
	m_targetActor = targetActor;
	AABBCollider* collider = new AABBCollider(40, 40, this);
	Actor::setCollider(collider);
	//sets the scale for the componet (sprite)
	getTransform()->setScale({ 2.5, 2.5 });
}

/// <summary>
/// Creates and spawns the enemy's health UI and its components
/// </summary>
void Enemy::start()
{


	//called start
	Character::start();
	//incruments the enemy count

	//Made a intece of healthDisplay
	HealthDisplay* enemyHealthDisplay = new HealthDisplay(10, -3, this);
	//added the healthDisplay to the currentScene
	Engine::getCurrentScene()->addUIElement(enemyHealthDisplay);

	//Made a intece of enemy animation
	EnemyAnimationsComponent* enemyAnimationsComponent = new EnemyAnimationsComponent("Sprites/sprites/characters/skeleton.png", "sprites/sprites/characters/skeletonleft.png", 6, 5, 8);
	//made the instence
	addComponent(enemyAnimationsComponent);

	//initializes the followComonet and sets the target Actor...
	m_followComponent = new FollowComponent( "Follow Component", m_targetActor);
	//...adds the componet to the enemy
	addComponent(m_followComponent);
}

/// <summary>
/// Called when an enemy dies
/// </summary>
void Enemy::end()
{
	if (!m_ended)
	{
		m_enemyCount--;
		m_ended = true;
	}
}

void Enemy::update(float deltaTime)
{

	//Then update
	Character::update(deltaTime);

	//DrawRectangleLines((getTransform()->getWorldPosition().x), (getTransform()->getWorldPosition().y), 40, 40, BLACK);

	//allows the for the enmey to move my get the move Componet and setting its velocity and putting in the get mvoe Axis then multipling 
	//... with its speed
	if (getHealthComponent()->getHealth() > 0)
		Character::getMoveComponent()->setVelocity(m_followComponent->getMoveAxis() * Character::getSpeed());
	else
	{
		m_deathTimeTracker += deltaTime;
		getMoveComponent()->setVelocity({ 0, 0 });
		end();
		
		//if (m_deathTimeTracker > 5)
		//{
		//	Engine::getCurrentScene()->destroy(this);
		//}
		
	}


}

void Enemy::onCollision(Actor* other)
{
	//If the other actor is an Attack actor, then take damage
	if (other->getName() == "Attack")
	{
		getHealthComponent()->takeDamage();
	}
}
