#include "PlayerAnimationsComponent.h"
#include "AnimatedSpriteComponent.h"
#include "Component.h"
#include "Actor.h"
#include "Transform2D.h"

PlayerAnimationsComponent::PlayerAnimationsComponent(const char* rightPath, const char* leftPath, int xFrames, int yFrames)
	: AnimatedSpriteComponent(rightPath, leftPath, xFrames, yFrames)
{

}

void PlayerAnimationsComponent::updateFrames(float deltaTime)
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
			if (getCurrentXFrame() > 5) setCurrentYFrame(0);
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
			if (getCurrentXFrame() < 0) setCurrentXFrame(5);
		}
		else if (getCurrentXFrame() == 2)
			//If the current x frame reaches the end of the tile image, set it back to 0
			if (getCurrentXFrame() < 2) setCurrentXFrame(5);
	}

	getFrameRec()->x = getCurrentXFrame() * getTexture()->width / 6;
	getFrameRec()->y = getCurrentYFrame() * getTexture()->height / 5;
}
