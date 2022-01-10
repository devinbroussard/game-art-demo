#pragma once
#include "Component.h"
class Character;

class AttackComponent :
	public Component
{
public:
	//Made a default contructor for the Attack Componet
	AttackComponent(float fps, int attackFrames);
	~AttackComponent() override {};

	Character* getCharacterOwner() { return (Character*)getOwner(); }
	bool getIsAttacking() { return m_isAttacking; }
	void startAttacking() { m_isAttacking = true; }

	//called update
	void update(float deltaTime) override;

private:
	int m_attackFrames;
	float m_frameDuration;
	bool m_isAttacking;
	float m_timeTracker;
	float m_fps;
};

