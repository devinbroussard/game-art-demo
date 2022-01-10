#include "HeartUI.h"
#include "SpriteComponent.h"
#include "HealthDisplay.h"
#include "Transform2D.h"
#include "Character.h"
#include "Engine.h"

HeartUI::HeartUI(float x, float y, Character* owner, HealthDisplay* display)
	: Actor(x, y, "HeartUI")
{
	m_owner = owner;
	display->getTransform()->addChild(getTransform());
	m_spinDuration = 1.2f;
}

void HeartUI::start()
{
	m_spinTimer = 0;
	m_spriteComponent = new SpriteComponent("Sprites/sprites/objects/heart.png");
	addComponent(m_spriteComponent);

	Actor::start();
}

void HeartUI::update(float deltaTime)
{

	Actor::update(deltaTime);
}

void HeartUI::killHeart(float deltaTime)
{
	spinHeart(deltaTime);
	if (m_isBlack) return;

	delete m_spriteComponent->getTexture();
	Texture2D* texture = new Texture2D(LoadTexture("Sprites/sprites/objects/deadheart.png"));                              
	m_spriteComponent->setTexture(texture);

	m_isBlack = true;	
}

void HeartUI::spinHeart(float deltaTime)
{
	m_spinTimer += deltaTime;
	if (m_spinTimer < m_spinDuration)
		getTransform()->rotate(0.01f);
	else getTransform()->setRotation(0);
}
