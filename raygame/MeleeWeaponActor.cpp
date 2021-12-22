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
	getTransform()->setScale({ 70, 70 });
	m_doSwing = false;
}

bool MeleeWeaponActor::getSwingInput()
{
	return m_owner->getInputComponent()->getAttackInput();
}

void MeleeWeaponActor::start()
{
	m_owner->getTransform()->addChild(getTransform());

	MeleeSwingComponent* meleeSwingComponent = new MeleeSwingComponent(5, 5);
	addComponent(meleeSwingComponent);
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
