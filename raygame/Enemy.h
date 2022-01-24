#pragma once
#include "Character.h"
#include "AABBCollider.h"


class MainScene;
class FollowComponent;


class Enemy :
	public Character
{
public:
	Enemy(float x, float y, const char* name, float speed, Character* targetActor);
	~Enemy() override;

	void start() override;
	void end() override;
	void update(float deltaTime);
	int gethealth() { return m_maxHealth; }

	//made a int to keep the enemy count and made it static
	static int m_enemyCount;
	void  onCollision(Actor* other);

private:
	/// <summary>
	/// Stores whether or not the end function has been called
	/// </summary>
	bool m_ended;
	int m_maxHealth;
	Character* m_targetActor;
	FollowComponent* m_followComponent;
	/// <summary>
	/// How long the character has been dead
	/// </summary>
	float m_deathTimeTracker;
};

