#include "PlayerAnimationsComponent.h"
#include "Component.h"

void PlayerAnimationsComponent::updateFrames(float deltaTime)
{
	//gets the y and x then updates them
	getTexture()->width = getWidth() * getOwner()->getTransform()->getScale().x;
	getTexture()->height = getHeight() * getOwner()->getTransform()->getScale().y;

	getFrameRec()->width = getTexture()->width / 6;
	getFrameRec()->height = getTexture()->height / 5;

	m_timeTracker += deltaTime;

	if (m_timeTracker >= (1 / m_fps) && !m_textureIsLeft)
	{
		m_timeTracker = 0;
		m_currentXFrame++;

		if (m_currentYFrame > 2)
		{
			//If the current x frame reaches the end of the tile image, set it back to 0
			if (m_currentXFrame > 5) m_currentXFrame = 0;
		}
		else if (m_currentYFrame == 2)
			//If the current x frame reaches the end of the tile image, set it back to 0
			if (m_currentXFrame > 3) m_currentXFrame = 0;
	}
	else if (m_timeTracker >= (1 / m_fps) && m_textureIsLeft)
	{
		m_timeTracker = 0;
		m_currentXFrame--;

		if (m_currentYFrame > 2)
		{
			//If the current x frame reaches the end of the tile image, set it back to 0
			if (m_currentXFrame < 0) m_currentXFrame = 5;
		}
		else if (m_currentYFrame == 2)
			//If the current x frame reaches the end of the tile image, set it back to 0
			if (m_currentXFrame < 2) m_currentXFrame = 5;
	}

	m_frameRec.x = m_currentXFrame * getTexture()->width / 6;
	m_frameRec.y = m_currentYFrame * getTexture()->height / 5;
}
