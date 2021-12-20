#pragma once
#include "Actor.h"
class Player;

class MeleeWeaponActor :
	public Actor
{
public:
	MeleeWeaponActor(Player* owner);
	~MeleeWeaponActor() {}

	bool getSwingInput();

	void start() override;
	void update(float deltaTime) override;

private:
	bool m_doSwing;
	Player* m_owner;
	
};

