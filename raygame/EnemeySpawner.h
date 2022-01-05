#pragma once
#include "Actor.h"
#include "Enemy.h"
#include "MainScene.h"
#include "Engine.h"

class Player;

class EnemeySpawner :
	public Actor
{
public:
	//made a default contructor that takes in a player pointer
	EnemeySpawner(Player* player) { m_player = player; }
	//update form the engine class
	void update(float deltaTime) override;
private:
	Player* m_player;
};

