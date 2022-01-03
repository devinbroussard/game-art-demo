#pragma once
#include "Character.h"
#include "FollowComponent.h"

class Enemy :
	public Character
{
public:
	Enemy(float x, float y, const char* name, float speed, int maxHealth, Actor* targetActor);
	~Enemy() {}

	void start() override;
	void update(float deltaTime);

private:
	Actor* m_targetActor;
	FollowComponent* m_followComponet;
};

