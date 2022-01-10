#include "Character.h"
#include "HealthComponent.h"
#include "MoveComponent.h"
#include "SpriteComponent.h"
#include "FollowComponent.h"

Character::Character(float x, float y, const char* name, float speed) :
	Actor::Actor(x, y, name)
{
	m_speed = speed;
	m_firingCooldown = 0.3f;

	m_healthComponent = nullptr;
	m_moveComponent = nullptr;
}

Character::~Character()
{
}


/// <summary>
/// Adds all of the character's components to its components array
/// </summary>
void Character::start()
{
	m_healthComponent = new HealthComponent(3);
	m_moveComponent = new MoveComponent();
	
	addComponent(m_healthComponent);
	addComponent(m_moveComponent);

	//adds both of the healthcomponet and the move componet to the charactor
	addComponent(healthComponent);
	addComponent(m_moveComponent);

	//calls start
	Actor::start();
}

/// <summary>
/// Called every frame
/// </summary>
/// <param name="deltaTime">The amount of time that has passed between frames</param>
void Character::update(float deltaTime)
{
	Actor::update(deltaTime);
}

/// <summary>
/// Called every frame
/// </summary>
void Character::draw()
{
	Actor::draw();
}
