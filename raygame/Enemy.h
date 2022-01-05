#pragma once
#include "Character.h"

class MainScene;
class FollowComponent;
//class InputComponent;

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

	//made a int to keep the enemy count and made it static
	static int m_enemyCount;
	//InputComponent* getInputComponent() { return m_inputComponent; }

private:
	Actor* m_targetActor;
	FollowComponent* m_followComponent;
	MainScene* m_mainScene;
	//InputComponent* m_inputComponent;
};

