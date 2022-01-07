#include "AnimatedSpriteComponent.h"
#include "Character.h"

void AnimatedSpriteComponent::getCurrentFrames()
{
	//Getting whether or not the player is moving left or right
	if (0 < getCharacter()->getVelocity().x && m_textureIsLeft)
	{
		setTexture(m_rightTexture);
		m_textureIsLeft = false;
	}
	if (getCharacter()->getVelocity().x < 0 && !m_textureIsLeft)
	{
		setTexture(m_leftTexture);
		m_textureIsLeft = true;
	}

	//Getting whether or not the player is standing still
	if (getCharacter()->getVelocity().x && getCharacter()->getVelocity().y == 0)
		m_currentYFrame = 1;
	else m_currentYFrame = 0;

	//Getting whether or not the player is attacking
	if (getCharacter()->getIsAttacking())
		m_currentYFrame = 2;
}
