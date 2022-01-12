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
};

