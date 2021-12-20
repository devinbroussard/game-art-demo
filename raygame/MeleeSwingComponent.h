#pragma once
#include "Component.h"
class MeleeSwingComponent :
	public Component
{
public:
	MeleeSwingComponent();
	~MeleeSwingComponent();

	void start() override;
	void update(float deltaTime) override;

private:
	MeleeWeaponActor* m_owner;
	float m_swingTimer;
	float m_swingDuration;
};

