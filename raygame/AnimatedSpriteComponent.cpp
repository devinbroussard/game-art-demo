#include "AnimatedSpriteComponent.h"
#include "Character.h"
#include "Component.h"
#include "Transform2D.h"

AnimatedSpriteComponent::AnimatedSpriteComponent(const char* rightPath, const char* leftPath, int xFrames, int yFrames) :
	SpriteComponent(rightPath, "AnimatedSpriteComponent")
{
	//This is the path that the textur is folling to get its png
	m_rightTexture = new Texture2D(LoadTexture(rightPath));
	m_leftTexture = new Texture2D(LoadTexture(leftPath));

	//gives it fps and a Frame counter that is x and y
	m_fps = 8;
	m_timeTracker = 0;
	m_currentXFrame = 0;
	m_currentYFrame = 0;
	m_xFrameCount = xFrames;
	m_yFrameCount = yFrames;
}

AnimatedSpriteComponent::~AnimatedSpriteComponent()
{
	UnloadTexture(*m_leftTexture);
	UnloadTexture(*m_rightTexture);

	delete m_leftTexture;
	delete m_rightTexture;
}

void AnimatedSpriteComponent::update(float deltaTime)
{
	//gets the current frames then...
	getCurrentFrames();
	//updates those frames by deltaTime
	updateFrames(deltaTime);
}

void AnimatedSpriteComponent::draw()
{
	//Gets the world Posistion for the x and the y
	Vector2 worldPosition = { Component::getOwner()->getTransform()->getWorldPosition().x, getOwner()->getTransform()->getWorldPosition().y };
	//draws the texture using the world position and the frameRec
	DrawTextureRec(*getTexture(), m_frameRec, worldPosition, WHITE);
}

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

void AnimatedSpriteComponent::updateFrames(float deltaTime)
{
	//gets the y and x then updates them
	getTexture()->width = getWidth() * getOwner()->getTransform()->getScale().x;
	getTexture()->height = getHeight() * getOwner()->getTransform()->getScale().y;

	m_frameRec.width = getTexture()->width / 6;
	m_frameRec.height = getTexture()->height / 5;

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
