#include "PlayerSpriteComponent.h"
#include "Actor.h"
#include "Transform2D.h"
#include "Player.h"
#include "InputComponent.h"
#include <Vector2.h>

PlayerSpriteComponent::PlayerSpriteComponent(const char* name) :
	SpriteComponent("Sprites/sprites/characters/player.png", name)
{
	m_rightTexture = new Texture2D(LoadTexture("Sprites/sprites/characters/player.png"));
	m_leftTexture = new Texture2D(LoadTexture("Sprites/sprites/characters/playerleft.png"));

	m_framesSpeed = 12;
	m_framesCounter = 0;
	m_currentXFrame = 0;
	m_currentYFrame = 0;
}

PlayerSpriteComponent::~PlayerSpriteComponent()
{
	UnloadTexture(*getTexture());
	delete getTexture();
}

void PlayerSpriteComponent::update(float deltaTime)
{
	getCurrentFrames();
	updateFrames();
}

void PlayerSpriteComponent::draw()
{

	Vector2 worldPosition = { getOwner()->getTransform()->getWorldPosition().x, getOwner()->getTransform()->getWorldPosition().y };
	DrawTextureRec(*getTexture(), m_frameRec, worldPosition, WHITE);
}

void PlayerSpriteComponent::getCurrentFrames()
{
	//Getting whether or not the player is moving left or right
	if (0 < getPlayerOwner()->getInputComponent()->getMoveAxis().x)
		setTexture(m_rightTexture);
	if (getPlayerOwner()->getInputComponent()->getMoveAxis().x < 0)
		setTexture(m_leftTexture);

	//Getting whether or not the player is standing still
	if (getPlayerOwner()->getInputComponent()->getMoveAxis().getMagnitude() > 0)
		m_currentYFrame = 1;
	else m_currentYFrame = 0;

	//Getting whether or not the player is attacking
	if (getPlayerOwner()->getInputComponent()->getAttackInput())
		m_currentYFrame = 2;
}

void PlayerSpriteComponent::updateFrames()
{
	getTexture()->width = getWidth() * getOwner()->getTransform()->getScale().x;
	getTexture()->height = getHeight() * getOwner()->getTransform()->getScale().y;

	m_frameRec.width = getTexture()->width / 6;
	m_frameRec.height = getTexture()->height / 5;

	m_framesCounter++;
	if (m_framesCounter >= (60 / m_framesSpeed))
	{
		m_framesCounter = 0;
		m_currentXFrame++;

		if (m_currentXFrame > 5) m_currentXFrame = 0;

		m_frameRec.x = m_currentXFrame * getTexture()->width / 6;
		m_frameRec.y = m_currentYFrame * getTexture()->height / 5;
	}
}
