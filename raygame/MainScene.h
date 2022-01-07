#pragma once
#include "Scene.h"
#include <raylib.h>


class EnemeySpawner;

class MainScene :
	public Scene
{
public:
	//called start
	void start() override;
	void draw() override;

private:
	//is the background of the game
	Texture2D m_map;
	//is the number of enemies that is allowed to spawn
	int m_enemyCounter;
	EnemeySpawner* m_enemySpawner;
	
};

