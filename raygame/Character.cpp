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
	m_maxHealth = 3;
}

Character::~Character()
{
}

void Character::setVelocity(float x, float y)
{
}

/// <summary>
/// Adds all of the character's components to its components array
/// </summary>
void Character::start()
{
	m_healthComponent = dynamic_cast<HealthComponent*>(addComponent(new HealthComponent(m_maxHealth, this)));
	m_moveComponent = dynamic_cast<MoveComponent*>(addComponent(new MoveComponent()));

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
