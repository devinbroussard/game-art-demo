#include "HeartUI.h"
#include "SpriteComponent.h"
#include "HealthDisplay.h"
#include "Transform2D.h"
#include "Character.h"+

HeartUI::HeartUI(float x, float y, Character* owner, HealthDisplay* display)
	: Actor(x, y, "HeartUI")
{
	m_owner = owner;
	display->getTransform()->addChild(getTransform());
}

void HeartUI::start()
{
	SpriteComponent* spriteComponent = new SpriteComponent("Sprites/sprites/objects/heart.png");

	addComponent(spriteComponent);

	Actor::start();
}
