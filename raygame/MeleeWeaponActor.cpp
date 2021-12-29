#include "MeleeWeaponActor.h"
#include "SpriteComponent.h"
#include "Actor.h"
#include "Player.h"
#include "Transform2D.h"
#include "InputComponent.h"
#include "MeleeSwingComponent.h"

MeleeWeaponActor::MeleeWeaponActor(Player* owner)
{
	m_owner = owner;
	getTransform()->setScale({ 120, 120 });
	m_doSwing = false;
}

bool MeleeWeaponActor::getSwingInput()
{
	return m_owner->getInputComponent()->getAttackInput();
}

void MeleeWeaponActor::start()
{
	m_owner->getTransform()->addChild(getTransform());

	MeleeSwingComponent* meleeSwingComponent = new MeleeSwingComponent(0.7, 0.3);
	addComponent(meleeSwingComponent);
	SpriteComponent* spriteComponent = new SpriteComponent("Sprites/bat.png");
	addComponent(spriteComponent);
	getTransform()->setRotation(2 * PI);

	Actor::start();
}

void MeleeWeaponActor::update(float deltaTime)
{
	getTransform()->setLocalPosition({ 0.3, 0 });
	Actor::update(deltaTime);
}
