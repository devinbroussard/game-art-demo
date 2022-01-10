#include "Character.h"
#include "HealthComponent.h"
#include "MoveComponent.h"
#include "SpriteComponent.h"
#include "FollowComponent.h"

Character::Character(float x, float y, const char* name, float speed, int maxHealth) :
	Actor::Actor(x, y, name)
{
	m_speed = speed;
	m_firingCooldown = 0.3f;
	m_maxHealth = maxHealth;
}

Character::~Character()
{
}


/// <summary>
/// Adds all of the character's components to its components array
/// </summary>
void Character::start()
{
	//Initilizes the health componet for every charctor...
	HealthComponent* healthComponent = new HealthComponent(m_maxHealth, this);
	//...renames the Movecomponet to the m)moveComponet
	m_moveComponent = new MoveComponent();

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
