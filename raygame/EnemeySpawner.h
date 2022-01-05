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
	EnemeySpawner(Player* player) { m_player = player; }
	void update(float deltaTime) override;
private:
	Player* m_player;
};

