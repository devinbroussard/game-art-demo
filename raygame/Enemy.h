#pragma once
#include "Character.h"
class FollowComponent;

class Enemy :
	public Character
{
public:
	Enemy(float x, float y, const char* name, float speed, int maxHealth, Actor* targetActor);
	~Enemy() {};

	void start() override;
	void update(float deltaTime);

private:
	Actor* m_targetActor;
	FollowComponent* m_followComponent;
};

