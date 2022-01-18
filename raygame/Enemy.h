#pragma once
#include "Character.h"
#include "AABBCollider.h"


class MainScene;
class FollowComponent;


class Enemy :
	public Character
{
public:
	Enemy(float x, float y, const char* name, float speed, Actor* targetActor);
	~Enemy() {};

	void start() override;
	void end() override;
	void update(float deltaTime);
	int gethealth() { return m_maxHealth; }

	//made a int to keep the enemy count and made it static
	static int m_enemyCount;
	void  onCollision(Actor* other);

private:
	bool m_ended;
	int m_maxHealth;
	Actor* m_targetActor;
	FollowComponent* m_followComponent;
	MainScene* m_mainScene;
	AABBCollider* m_aabbCollider;
	float m_deathTimeTracker;
};

