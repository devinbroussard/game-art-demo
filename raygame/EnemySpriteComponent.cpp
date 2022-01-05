#include "EnemySpriteComponent.h"
#include "Actor.h"
#include "Transform2D.h"
#include "Enemy.h"
#include "InputComponent.h"
#include <Vector2.h>
#include <iostream>

EnemySpriteComponent::EnemySpriteComponent(const char* name) :
	SpriteComponent("Sprites/sprites/characters/player.png", name)
{
	m_rightTexture = new Texture2D(LoadTexture("Sprites/sprites/characters/player.png"));
	m_leftTexture = new Texture2D(LoadTexture("Sprites/sprites/characters/playerleft.png"));

	m_fps = 8;
	m_timeTracker = 0;
	m_currentXFrame = 0;
	m_currentYFrame = 0;
}

EnemySpriteComponent::~EnemySpriteComponent()
{
	UnloadTexture(*getTexture());
	delete getTexture();
}

void EnemySpriteComponent::update(float deltaTime)
{
	getCurrentFrames();
	updateFrames(deltaTime);
}

void EnemySpriteComponent::draw()
{
	Vector2 worldPosition = { getOwner()->getTransform()->getWorldPosition().x, getOwner()->getTransform()->getWorldPosition().y };
	DrawTextureRec(*getTexture(), m_frameRec, worldPosition, WHITE);
}

void EnemySpriteComponent::getCurrentFrames()
{
	//Getting whether or not the player is moving left or right
	if (0 <  getPlayerOwner()->getFollowComponet())
	{
		setTexture(m_rightTexture);
		m_textureIsLeft = false;
	}
	if (getPlayerOwner()->getFollowComponet() < 0)
	{
		setTexture(m_leftTexture);
		m_textureIsLeft = true;
	}

	//Getting whether or not the player is standing still
	if (getPlayerOwner()->getFollowComponet() > 0)
		m_currentYFrame = 1;
	else m_currentYFrame = 0;

	//Getting whether or not the player is attacking
	if (getPlayerOwner()->getFollowComponet())
		m_currentYFrame = 2;
}

void EnemySpriteComponent::updateFrames(float deltaTime)
{
	getTexture()->width = getWidth() * getOwner()->getTransform()->getScale().x;
	getTexture()->height = getHeight() * getOwner()->getTransform()->getScale().y;

	m_frameRec.width = getTexture()->width / 6;
	m_frameRec.height = getTexture()->height / 5;

	std::cout << (1 / m_fps) << std::endl;
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
