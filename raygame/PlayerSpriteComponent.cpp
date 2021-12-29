#include "PlayerSpriteComponent.h"
#include "Actor.h"
#include "Transform2D.h"

PlayerSpriteComponent::PlayerSpriteComponent(const char* name) :
	SpriteComponent("Sprites/sprites/characters/player.png", name)
{
	m_framesSpeed = 8;
	m_framesCounter = 0;
	m_currentFrame = 0;
}

PlayerSpriteComponent::~PlayerSpriteComponent()
{
	UnloadTexture(*getTexture());
	delete getTexture();
}

void PlayerSpriteComponent::update(float deltaTime)
{
	getTexture()->width = getWidth() * getOwner()->getTransform()->getScale().x;
	getTexture()->height = getHeight() * getOwner()->getTransform()->getScale().y;

	m_framesCounter++;
	if (m_framesCounter >= (60 / m_framesSpeed))
	{
		m_framesCounter = 0;
		m_currentFrame++;

		if (m_currentFrame > 5) m_currentFrame = 0;

		m_frameRec.x = (float)m_currentFrame * (float)getTexture()->width / 6;
		//m_frameRec.y = (float)m_currentFrame * (float)getTexture()->height / 5;
	}
}

void PlayerSpriteComponent::draw()
{

	Vector2 worldPosition = { getOwner()->getTransform()->getWorldPosition().x, getOwner()->getTransform()->getWorldPosition().y };
	DrawTextureRec(*getTexture(), m_frameRec, worldPosition, WHITE);
}
