#pragma once
#include "Actor.h"
class Character;
class HealthDisplay;

class HeartUI :
	public Actor
{
public:
	HeartUI(float x, float y, Character* owner, HealthDisplay* display);

	void start() override;
	void killHeart();
	void rotateHeart();

private:
	Character* m_owner;
	HealthDisplay* m_display;
};

