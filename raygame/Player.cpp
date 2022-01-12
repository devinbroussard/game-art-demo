#include "Player.h"
#include "InputComponent.h"
#include <Vector2.h>
#include "MoveComponent.h"
#include "PlayerAnimationsComponent.h"
#include "Transform2D.h"
#include "Actor.h"

Player::Player(float x, float y, const char* name, float speed) :
	Character::Character(x, y, name, speed)
{
	m_inputComponent = nullptr;
	AABBCollider* collider = new AABBCollider(40, 40, this);
	Actor::setCollider(collider);

}

void Player::start()
{
	//adds the player animatimes to the player
	PlayerAnimationsComponent* playerAnimationsComponent = new PlayerAnimationsComponent("Sprites/sprites/characters/player.png", "Sprites/sprites/characters/playerleft.png", 6, 5, 8);
	//initalizes the input Component to player
	m_inputComponent = new InputComponent(this);
	//adds the player animations to player
	addComponent(playerAnimationsComponent);
	//adds the input component to plyaer
	addComponent(m_inputComponent);
	//set the players scale
	getTransform()->setScale({ 2.5, 2.5 });

	Character::start();
}

void Player::update(float deltaTime)
{
	
	DrawRectangleLines((getTransform()->getWorldPosition().x) , (getTransform()->getWorldPosition().y), 50, 50, BLACK);
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
	getHealthComponent()->takeDamage();

	//then updateing
	Character::update(deltaTime);
}
//happens when there is a collision
void Player::onCollision(Actor* other)
{
}
