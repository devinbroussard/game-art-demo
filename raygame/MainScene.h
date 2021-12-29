#pragma once
#include "Scene.h"
#include <raylib.h>

class MainScene :
	public Scene
{
public:
	void start() override;
<<<<<<< Updated upstream
=======
	void draw() override;

private:
	Texture2D m_map;
>>>>>>> Stashed changes
};

