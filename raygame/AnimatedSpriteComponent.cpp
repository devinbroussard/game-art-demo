#include "AnimatedSpriteComponent.h"
#include "Character.h"
#include "Component.h"
#include "Transform2D.h"
#include "MoveComponent.h"

AnimatedSpriteComponent::AnimatedSpriteComponent(const char* rightPath, const char* leftPath, int xFrames, int yFrames, float fps) :
	SpriteComponent(rightPath, "AnimatedSpriteComponent")
{
	//This is the path that the textur is folling to get its png
	m_rightTexture = new Texture2D(LoadTexture(rightPath));
	m_leftTexture = new Texture2D(LoadTexture(leftPath));

	//gives it fps and a Frame counter that is x and y
	m_fps = fps;
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
	if (0 < getCharacter()->getMoveComponent()->getVelocity().x && m_textureIsLeft)
	{
		setTexture(m_rightTexture);
		m_textureIsLeft = false;
	}
	if (getCharacter()->getMoveComponent()->getVelocity().x < 0 && !m_textureIsLeft)
	{
		setTexture(m_leftTexture);
		m_textureIsLeft = true;
	}
	//Getting whether or not the player is standing still
	if (getCharacter()->getMoveComponent()->getVelocity().x != 0 || getCharacter()->getMoveComponent()->getVelocity().y != 0)
		m_currentYFrame = 1;
	else m_currentYFrame = 0;

	//Getting whether or not the player is attacking
	if (getCharacter()->getIsAttacking() )
	{
		if (!m_startAttack)
		{
			if (!m_textureIsLeft)
				m_currentXFrame = 0;
			else m_currentXFrame = 5;
		}

		m_currentYFrame = 2;
		m_startAttack = true;
	}
}
