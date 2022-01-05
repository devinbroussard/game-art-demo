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

	void start() override;
	void update(float deltaTime) override;

	void idleFloat();
	void killHeart();
	void rotateHeart();

private:
	Character* m_owner;
	SpriteComponent* m_spriteComponent;
};

