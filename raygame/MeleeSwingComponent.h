#pragma once
#include "Component.h"
class MeleeWeaponActor;

class MeleeSwingComponent :
	public Component
{
public:
	MeleeSwingComponent(float swingDuration, float swingCooldown);
	~MeleeSwingComponent();

	MeleeWeaponActor* getMeleeWeapon() { return dynamic_cast<MeleeWeaponActor*>(getOwner()); }

	void start() override;
	void update(float deltaTime) override;

private:
	float m_swingTimer;
	float m_swingDuration;
	float m_swingCooldown;
};

