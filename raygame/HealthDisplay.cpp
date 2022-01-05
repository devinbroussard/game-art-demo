#include "HealthDisplay.h"
#include "SpriteComponent.h"
#include "Character.h"

void HealthDisplay::start()
{
	m_firstHeart = new SpriteComponent("Sprites/sprites/objects/heart.png");
	m_secondHeart = new SpriteComponent("Sprites/sprites/objects/heart.png");
	m_thirdHeart = new SpriteComponent("Sprites/sprites/objects/hearts.png");

	Actor::start();
}
