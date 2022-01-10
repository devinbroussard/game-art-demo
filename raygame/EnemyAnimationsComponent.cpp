#include "EnemyAnimationsComponent.h"
#include "Transform2D.h"
#include "Actor.h"

EnemyAnimationsComponent::EnemyAnimationsComponent(const char* rightPath, const char* leftPath, int xFrames, int yFrames)
	: AnimatedSpriteComponent(rightPath, leftPath, 6, 5)
{ }

void EnemyAnimationsComponent::updateFrames(float deltaTime)
{
	//gets the y and x then updates them
	getTexture()->width = getWidth() * getOwner()->getTransform()->getScale().x;
	getTexture()->height = getHeight() * getOwner()->getTransform()->getScale().y;

	getFrameRec()->width = getTexture()->width / 6;
	getFrameRec()->height = getTexture()->height / 5;

	setTimeTracker(getTimeTracker() + deltaTime);

	if (getTimeTracker() >= (1 / getFps()) && !getIsTextureLeft())
	{
		setTimeTracker(0);
		setCurrentXFrame(getCurrentXFrame() + 1);

		if (getCurrentYFrame() > 2)
		{
			//If the current x frame reaches the end of the tile image, set it back to 0
			if (getCurrentXFrame() > getXFrameCount()) setCurrentYFrame(0);
		}
		else if (getCurrentYFrame() == 2)
			//If the current x frame reaches the end of the tile image, set it back to 0
			if (getCurrentXFrame() > 3) setCurrentXFrame(0);
	}
	else if (getTimeTracker() >= (1 / getFps()) && getIsTextureLeft())
	{
		setTimeTracker(0);
		setCurrentXFrame(getCurrentXFrame() - 1);

		if (getCurrentYFrame() > 2)
		{
			//If the current x frame reaches the end of the tile image, set it back to 0
			if (getCurrentXFrame() < 0) setCurrentXFrame(getXFrameCount() - 1);
		}
		else if (getCurrentYFrame() == 2)
			//If the current x frame reaches the end of the tile image, set it back to 0
			if (getCurrentXFrame() < 2)
			{
				setCurrentXFrame(getXFrameCount() - 1);
				setStartAttack(false);
			}
	}

	getFrameRec()->x = getCurrentXFrame() * getTexture()->width / getXFrameCount();
	getFrameRec()->y = getCurrentYFrame() * getTexture()->height / getYFrameCount();
}
