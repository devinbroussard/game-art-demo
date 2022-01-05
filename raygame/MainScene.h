#pragma once
#include "Scene.h"
#include <raylib.h>


class EnemeySpawner;

class MainScene :
	public Scene
{
public:
	void start() override;
	void draw() override;

private:
	Texture2D m_map;
	int m_enemyCounter;
	EnemeySpawner* m_enemySpawner;
	
};

