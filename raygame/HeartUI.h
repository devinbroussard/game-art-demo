#pragma once
#include "Actor.h"

class Character;
class SpriteComponent;
class HealthDisplay;

class HeartUI :
	public Actor
{
public:
	HeartUI(float x, float y, Character* owner, HealthDisplay* display);
	~HeartUI() override;

	void start() override;
	void update(float deltaTime) override;

	void killHeart(float deltaTime);
	void spinHeart(float deltaTime);

private:
	Character* m_owner;
	SpriteComponent* m_spriteComponent;
	float m_spinTimer;
	float m_spinDuration;
	bool m_isBlack;
};

