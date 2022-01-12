#pragma once
#include "Component.h"
class Character;
class Actor;

class AttackComponent :
	public Component
{
public:
	//Made a default contructor for the Attack Componet
	AttackComponent(float fps, int attackFrames);
	~AttackComponent() override {};

	Character* getCharacterOwner() { return (Character*)getOwner(); }
	bool getIsAttacking() { return m_isAttacking; }
	void setIsAttacking(bool value) { m_isAttacking = value; }

	void start() override;
	//called update
	void update(float deltaTime) override;

private:
	Actor* m_attackActor;
	bool m_attackStarted;
	int m_attackFrames;
	bool m_isAttacking;
	float m_timeTracker;
	float m_fps;
};

