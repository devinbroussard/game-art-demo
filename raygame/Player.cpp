#include "Player.h"
#include "InputComponent.h"
#include <Vector2.h>
#include "MoveComponent.h"
#include "PlayerSpriteComponent.h"

Player::Player(float x, float y, const char* name, float speed, int maxHealth) :
	Character::Character(x, y, name, speed, maxHealth)
{
}

void Player::start()
{
	// Set spawn point
	//Set move speed
	//Set position clamps
	PlayerSpriteComponent* playerSpriteComponent = new PlayerSpriteComponent();
	addComponent(playerSpriteComponent);
	getTransform()->setScale({1, 1});

	Character::start();
	m_inputComponent = dynamic_cast<InputComponent*>(addComponent(new InputComponent(this)));
	
}

void Player::update(float deltaTime)
{
	Character::getMoveComponent()->setVelocity(m_inputComponent->getMoveAxis() * Character::getSpeed());
	Character::update(deltaTime);
}
