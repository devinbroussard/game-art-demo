#include "Player.h"
#include "InputComponent.h"
#include <Vector2.h>
#include "MoveComponent.h"
#include "PlayerSpriteComponent.h"

Player::Player(float x, float y, const char* name, float speed) :
	Character::Character(x, y, name, speed)
{
	m_inputComponent = nullptr;
}

void Player::start()
{
	// Set spawn point
	//Set move speed
	//Set position clamps
	PlayerSpriteComponent* playerSpriteComponent = new PlayerSpriteComponent();
	addComponent(playerSpriteComponent);
	m_inputComponent = new InputComponent(this);
	addComponent(m_inputComponent);
	getTransform()->setScale({ 2.5, 2.5 });

	Character::start();
}

void Player::update(float deltaTime)
{
	Character::getMoveComponent()->setVelocity(m_inputComponent->getMoveAxis() * Character::getSpeed());
	getHealthComponent()->takeDamage();

	Character::update(deltaTime);
}
