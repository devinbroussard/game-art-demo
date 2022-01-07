#include "Player.h"
#include "InputComponent.h"
#include <Vector2.h>
#include "MoveComponent.h"
#include "PlayerSpriteComponent.h"
#include "Transform2D.h"
#include "AnimatedSpriteComponent.h"


Player::Player(float x, float y, const char* name, float speed, int maxHealth) :
	Character::Character(x, y, name, speed, maxHealth)
{
}

void Player::start()
{
	//Initializes the Player Sprite Componet
	PlayerSpriteComponent* playerSpriteComponent = new PlayerSpriteComponent();
	//Adds the componet to the player
	addComponent(playerSpriteComponent);
	//sets its scale
	getTransform()->setScale({2.5, 2.5});
	
	Character::start();
	//adds the input componet to the player and Initializes it.
	m_inputComponent = dynamic_cast<InputComponent*>(addComponent(new InputComponent(this)));
}

void Player::update(float deltaTime)
{
	//made to variables that made the scale go up or down
	float scaleUP = -5;
	float scaleDown = 1;
	//this is to increase the scale
	if (RAYLIB_H::IsKeyDown(KEY_Z))
	{
		getTransform()->setScale({ scaleUP,scaleUP });
		//getTransform()->scale({ scaleUP,scaleUP });

	}
	//This is to decrease the scale
	if (RAYLIB_H::IsKeyDown(KEY_X))
	{
		//getTransform()->scale({ scaleDown,scaleDown });
		getTransform()->setScale({ scaleDown,scaleDown });
		
	}

	//reset the scale for the caractor when scaling
	else if (RAYLIB_H::IsKeyDown(KEY_C))
	{
		//getTransform()->scale({ 2.5,2.5 });
		getTransform()->setScale({ 2.5,2.5 });
	}
	//moves the player by seting the velocity by mulitpling the move axis and the character speed
	Character::getMoveComponent()->setVelocity(m_inputComponent->getMoveAxis() * Character::getSpeed());
	//then updateing
	Character::update(deltaTime);
}
//happens when there is a collision
void Player::onCollision(Actor* other)
{
		
}
