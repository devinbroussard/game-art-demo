#pragma once
#include "Character.h"
#include "AABBCollider.h"


class MainScene;
class FollowComponent;


class Enemy :
	public Character
{
public:
	//deflat contructor for the enemy
	Enemy(float x, float y, const char* name, float speed, int maxHealth, Actor* targetActor);
	//default decontructor for the enemy
	~Enemy() {};

	void start() override;
	void update(float deltaTime);
	int gethealth() { return m_maxHealth; }

	//made a int to keep the enemy count and made it static
	static int m_enemyCount;
	void  onCollision(Actor* other);

private:
	int m_maxHealth;
	Actor* m_targetActor;
	FollowComponent* m_followComponent;
	MainScene* m_mainScene;
	AABBCollider* m_aabbCollider;
	//InputComponent* m_inputComponent;
};

