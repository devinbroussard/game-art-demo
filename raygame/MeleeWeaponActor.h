#pragma once
#include "Actor.h"
class MeleeWeaponActor :
	public Actor
{
public:
	MeleeWeaponActor(Actor* owner);
	~MeleeWeaponActor() {}

	Actor* getOwner() { return m_owner; }

	void start() override;
	void update(float deltaTime) override;

private:
	Player* m_owner;
	bool m_doSwing;
	
};

