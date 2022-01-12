#include "PlayerAnimationsComponent.h"
#include "AnimatedSpriteComponent.h"
#include "Component.h"
#include "Actor.h"
#include "Transform2D.h"
#include "Character.h"

PlayerAnimationsComponent::PlayerAnimationsComponent(const char* rightPath, const char* leftPath, int xFrames, int yFrames, float fps)
	: AnimatedSpriteComponent(rightPath, leftPath, xFrames, yFrames, fps)
{ }

/// <summary>
/// Updates the framerec, switching the frame that is drawn to the screen
/// </summary>
/// <param name="deltaTime"></param>
void PlayerAnimationsComponent::updateFrames(float deltaTime)
{
	//Changes the size of the sprite to match the actor's scale
	getTexture()->width = getWidth() * getOwner()->getTransform()->getScale().x;
	getTexture()->height = getHeight() * getOwner()->getTransform()->getScale().y;

	//Changes the size of the rectangle to match the size of the sprite
	getFrameRec()->width = getTexture()->width / 6;
	getFrameRec()->height = getTexture()->height / 5;

	//Adds deltatime to the time tracker
	setTimeTracker(getTimeTracker() + deltaTime);

	//If it is time to switch frames, the character is facing right, and the character is not dead...
	if (getTimeTracker() >= (1 / getFps()) && !getIsTextureLeft() && !getCharacterIsDead())
	{
		//Set time tracker back to 0
		setTimeTracker(0);
		//Increase the current frame by one
		setCurrentXFrame(getCurrentXFrame() + 1);

		//If the character is idle or running...
		if (getCurrentYFrame() < 2)
		{
			//If the current x frame reaches the end of the tile image, set it back to 0
			if (getCurrentXFrame() > getXFrameCount() - 1) setCurrentYFrame(0);
		}
		//Else if the character is attacking...
		else if (getCurrentYFrame() == 2)
		{
			//If the character reaches the end of the attack, stop attacking
			if (getCurrentXFrame() > 3)
			{
				getCharacter()->setAttacking(false);
				setStartAttack(false);
			}
		}
		//If the character reaches the end of the dying animation, set their dead bool to true
		else if (getCurrentYFrame() == 4)
		{
			if (getCurrentXFrame() > 2)  setCharacterIsDead(true);
		}
	}
	
	//Else if the player is facing right, not dead, and it is time to change frames
	else if (getTimeTracker() >= (1 / getFps()) && getIsTextureLeft() && !getCharacterIsDead())
	{
		//Set time tracker to 0
		setTimeTracker(0);
		//Decrease the current frame by one
		setCurrentXFrame(getCurrentXFrame() - 1);

		if (getCurrentYFrame() < 2)
		{
			//If the current x frame reaches the end of the tile image, set it back to 0
			if (getCurrentXFrame() < 0) setCurrentXFrame(getXFrameCount() - 1);
		}
		//If the character is attacking
		else if (getCurrentYFrame() == 2)
		{
			//If the current x frame reaches the end of the attack animation...
			if (getCurrentXFrame() < 2)
			{
				//Stop attacking
				getCharacter()->setAttacking(false);
				setStartAttack(false);
			}
		}
		//If the character is going through the dead animation...
		else if (getCurrentYFrame() == 4)
		{
			//If the current frame count is above what is should be, set it back to the max
			if (getCurrentXFrame() > getXFrameCount() - 1) setCurrentXFrame(5);
			//If the animation ends, set their dead bool to be true
			if (getCurrentXFrame() < 3)  setCharacterIsDead(true);
		}
	}
	//If the character is dead and facing right, always show their dead frame
	else if (getCharacterIsDead() && !getIsTextureLeft())
		setCurrentXFrame(2);
	//Else if the character is showing left, always show the left dead frame
	else if (getCharacterIsDead() && getIsTextureLeft())
		setCurrentXFrame(3);

	//Changes the frame rectangle's x and y values to match the current frame
	getFrameRec()->x = getCurrentXFrame() * getTexture()->width / getXFrameCount();
	getFrameRec()->y = getCurrentYFrame() * getTexture()->height / getYFrameCount();
}

void PlayerAnimationsComponent::draw()
{
	//Gets the world Posistion for the x and the y
	Vector2 worldPosition = { Component::getOwner()->getTransform()->getWorldPosition().x - 35 , getOwner()->getTransform()->getWorldPosition().y - 60};
	//draws the texture using the world position and the frameRec
	DrawTextureRec(*getTexture(), *getFrameRec(), worldPosition, WHITE);
}
