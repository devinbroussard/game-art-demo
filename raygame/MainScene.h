#pragma once
#include "Scene.h"
#include <raylib.h>

class MainScene :
	public Scene
{
public:
	void start() override;
	void draw() override;

private:
	Texture2D m_map;
};

