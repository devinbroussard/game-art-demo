#include "MeleeWeaponActor.h"
#include "SpriteComponent.h"
#include "Actor.h"
#include "Transform2D.h"

MeleeWeaponActor::MeleeWeaponActor(Actor* owner)
{
	m_owner = owner;
	getTransform()->setScale({ 70, 70 });
}

void MeleeWeaponActor::start()
{
	m_owner->getTransform()->addChild(getTransform());

	SpriteComponent* spriteComponent = new SpriteComponent("Sprites/bat.png");
	addComponent(spriteComponent);
	Actor::start();
	getTransform()->setRotation(PI);
}

void MeleeWeaponActor::update(float deltaTime)
{
	getTransform()->setLocalPosition({ 0.5, -0.1 });
	Actor::update(deltaTime);
}
