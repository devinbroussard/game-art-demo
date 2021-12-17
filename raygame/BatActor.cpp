#include "BatActor.h"
#include "SpriteComponent.h"
#include "Actor.h"
#include "Transform2D.h"

BatActor::BatActor(Actor* owner)
{
	m_owner = owner;
}

void BatActor::start()
{
	m_owner->getTransform()->addChild(getTransform());

	SpriteComponent* spriteComponent = new SpriteComponent("Sprites/bat.png");
	addComponent(spriteComponent);
	
}
