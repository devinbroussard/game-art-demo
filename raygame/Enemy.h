#pragma once
#include "Character.h"
#include "InputComponent.h"

class MainScene;
class FollowComponent;
//class InputComponent;

class Enemy :
	public Character
{
public:
	Enemy(float x, float y, const char* name, float speed, int maxHealth, Actor* targetActor);
	~Enemy() {};

	void start() override;
	void update(float deltaTime);

	static int m_enemyCount;
	//InputComponent* getInputComponent() { return m_inputComponent; }

private:
	Actor* m_targetActor;
	FollowComponent* m_followComponent;
	MainScene* m_mainScene;
	//InputComponent* m_inputComponent;
};

