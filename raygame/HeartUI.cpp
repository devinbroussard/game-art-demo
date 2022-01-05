#include "HeartUI.h"
#include "SpriteComponent.h"
#include "HealthDisplay.h"
#include "Transform2D.h"
#include "Character.h"

HeartUI::HeartUI(float x, float y, Character* owner, HealthDisplay* display)
	: Actor(x, y, "HeartUI")
{
	m_owner = owner;
	display->getTransform()->addChild(getTransform());
}

void HeartUI::start()
{
	m_spriteComponent = new SpriteComponent("Sprites/sprites/objects/heart.png");
	addComponent(m_spriteComponent);

	Actor::start();
}

void HeartUI::update(float deltaTime)
{
	if (m_owner)

	Actor::update(deltaTime);
}

void HeartUI::killHeart()
{
	m_spriteComponent->getTexture();
	Texture2D* texture = new Texture2D(LoadTexture("Sprites/sprites/objects/deadheart.png"));                              
	m_spriteComponent->setTexture(texture);
}
