#include "EnemyAnimationsComponent.h"
#include "Transform2D.h"
#include "Actor.h"
#include "Character.h"

EnemyAnimationsComponent::EnemyAnimationsComponent(const char* rightPath, const char* leftPath, int xFrames, int yFrames, float fps)
	: AnimatedSpriteComponent(rightPath, leftPath, 6, 5, fps)
{ }


/// <summary>
/// This makes the texture of the enemy update left and right...
/// </summary>
/// <param name="deltaTime"></param>
void EnemyAnimationsComponent::updateFrames(float deltaTime)
{
	//Updates the texture's width and height depending on the character's scale
	getTexture()->width = getWidth() * getOwner()->getTransform()->getScale().x;
	getTexture()->height = getHeight() * getOwner()->getTransform()->getScale().y;

	//Updates the rectangle's width and height based on the texture
	getFrameRec()->width = getTexture()->width / 6;
	getFrameRec()->height = getTexture()->height / 5;

	//Adds delta time to the time tracker
	setTimeTracker(getTimeTracker() + deltaTime);

	//If it is time to change frames, the texture is facing right, and the character is not dead...
	if (getTimeTracker() >= (1 / getFps()) && !getIsTextureLeft() && !getCharacterIsDead())
	{
		//Set the time tracker to be 0...
		setTimeTracker(0);
		//Increase the current x frame by one
		setCurrentXFrame(getCurrentXFrame() + 1);

		//If the character is in the idle or running animation...
		if (getCurrentYFrame() < 2)
		{
			//If the current x frame reaches the end of the tile image, set it back to 0
			if (getCurrentXFrame() > getXFrameCount() - 1) setCurrentYFrame(0);
		}
		//Else if the character is in the attacking animation...
		else if (getCurrentYFrame() == 2)
		{
			//Once they reach the end of the animation, set their attacking bools to be false
			if (getCurrentXFrame() > 3)
			{
				getCharacter()->setAttacking(false);
				setStartAttack(false);
			}
		}
		//If the character is in the death animation...
		else if (getCurrentYFrame() == 4)
		{
			//Once they reach the end of the animation, set their dead bool to be true
			if (getCurrentXFrame() > 4)  setCharacterIsDead(true);
		}
	}
	//If it is time to change frames, the texture is facing left, and the character is not dead
	else if (getTimeTracker() >= (1 / getFps()) && getIsTextureLeft() && !getCharacterIsDead())
	{
		//Set the time tracker to be false
		setTimeTracker(0);
		//Decrease the current x frame by one
		setCurrentXFrame(getCurrentXFrame() - 1);

		//If the character is in idle or running animation...
		if (getCurrentYFrame() < 2)
		{
			//If the current x frame reaches the end of the tile image, set it back to the start
			if (getCurrentXFrame() < 0) setCurrentXFrame(getXFrameCount() - 1);
		}
		//If the character is in the attacking animation...
		else if (getCurrentYFrame() == 2)
		{
			//If the current x frame reaches the end of the tile image, set it back to 0
			if (getCurrentXFrame() < 2)
			{
				getCharacter()->setAttacking(false);
				setStartAttack(false);
			}
		}
		//If the character is in the death animation...
		else if (getCurrentYFrame() == 4)
		{
			//If the current x frame is above the allowed amount, set it back to the start...
			if (getCurrentXFrame() > getXFrameCount() - 1) setCurrentXFrame(5);
			//Once the current x frame reaches the end of the animation, set the character's death bool to be true
			if (getCurrentXFrame() == 0)  setCharacterIsDead(true);
		}
	}
	//If the character is dead and facing right, show the right texture's dead frame
	else if (getCharacterIsDead() && !getIsTextureLeft())
		setCurrentXFrame(4);
	//Else if they are facing left, show the left texture's dead frame
	else if (getCharacterIsDead() && getIsTextureLeft())
		setCurrentXFrame(1);

	//Change the frame rectangle's x and y values to match the current frame
	getFrameRec()->x = getCurrentXFrame() * getTexture()->width / getXFrameCount();
	getFrameRec()->y = getCurrentYFrame() * getTexture()->height / getYFrameCount();
}

void EnemyAnimationsComponent::draw()
{
	//Gets the world Posistion for the x and the y
	Vector2 worldPosition = { Component::getOwner()->getTransform()->getWorldPosition().x - 55, getOwner()->getTransform()->getWorldPosition().y - 90 };
	//draws the texture using the world position and the frameRec
	DrawTextureRec(*getTexture(), *getFrameRec(), worldPosition, WHITE);
}
