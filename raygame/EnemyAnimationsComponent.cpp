#include "EnemyAnimationsComponent.h"
#include "Transform2D.h"
#include "Actor.h"
#include "Character.h"

EnemyAnimationsComponent::EnemyAnimationsComponent(const char* rightPath, const char* leftPath, int xFrames, int yFrames, float fps)
	: AnimatedSpriteComponent(rightPath, leftPath, 6, 5, fps)
{ }

void EnemyAnimationsComponent::updateFrames(float deltaTime)
{
	//gets the y and x then updates them
	getTexture()->width = getWidth() * getOwner()->getTransform()->getScale().x;
	getTexture()->height = getHeight() * getOwner()->getTransform()->getScale().y;

	getFrameRec()->width = getTexture()->width / 6;
	getFrameRec()->height = getTexture()->height / 5;

	setTimeTracker(getTimeTracker() + deltaTime);


	if (getTimeTracker() >= (1 / getFps()) && !getIsTextureLeft() && !getCharacterIsDead())
	{
		setTimeTracker(0);
		setCurrentXFrame(getCurrentXFrame() + 1);

		if (getCurrentYFrame() < 2)
		{
			//If the current x frame reaches the end of the tile image, set it back to 0
			if (getCurrentXFrame() > getXFrameCount() - 1) setCurrentYFrame(0);
		}
		else if (getCurrentYFrame() == 2)
		{
			if (getCurrentXFrame() > 3)
			{
				getCharacter()->setAttacking(false);
				setStartAttack(false);
			}
		}
		else if (getCurrentYFrame() == 4)
		{
			if (getCurrentXFrame() > 4)  setCharacterIsDead(true);
		}
	}
	else if (getTimeTracker() >= (1 / getFps()) && getIsTextureLeft() && !getCharacterIsDead())
	{
		setTimeTracker(0);
		setCurrentXFrame(getCurrentXFrame() - 1);

		if (getCurrentYFrame() < 2)
		{
			//If the current x frame reaches the end of the tile image, set it back to 0
			if (getCurrentXFrame() < 0) setCurrentXFrame(getXFrameCount() - 1);
		}
		else if (getCurrentYFrame() == 2)
		{
			//If the current x frame reaches the end of the tile image, set it back to 0
			if (getCurrentXFrame() < 2)
			{
				getCharacter()->setAttacking(false);
				setStartAttack(false);
			}
		}
		else if (getCurrentYFrame() == 4)
		{
			if (getCurrentXFrame() > getXFrameCount() - 1) setCurrentXFrame(5);

			if (getCurrentXFrame() == 0)  setCharacterIsDead(true);
		}
	}
	else if (getCharacterIsDead() && !getIsTextureLeft())
		setCurrentXFrame(4);
	else if (getCharacterIsDead() && getIsTextureLeft())
		setCurrentXFrame(1);

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
