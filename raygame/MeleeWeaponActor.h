#pragma once
#include "Actor.h"
class MeleeWeaponActor :
	public Actor
{
public:
	MeleeWeaponActor(Actor* owner);
	~MeleeWeaponActor() {}

	void start() override;
	void update(float deltaTime) override;

private:
	Actor* m_owner;
	
};

