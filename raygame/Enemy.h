#pragma once
#include "Character.h"
#include "AABBCollider.h"

class MainScene;
class FollowComponent;
//class InputComponent;

class Enemy :
	public Character
{
public:
	Enemy(float x, float y, const char* name, float speed, Actor* targetActor);
	~Enemy() {};

	void start() override;
	void update(float deltaTime);

	//made a int to keep the enemy count and made it static
	static int m_enemyCount;
	//InputComponent* getInputComponent() { return m_inputComponent; }

private:
	Actor* m_targetActor;
	FollowComponent* m_followComponent;
	MainScene* m_mainScene;
	AABBCollider* m_aabbCollider;
	//InputComponent* m_inputComponent;
};

