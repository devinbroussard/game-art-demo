#pragma once
#include <raylib.h>
#include "Engine.h"

class MenuScene :
	public Scene
{
public:
	void start() override;
	void update(float deltaTime) override;
	void draw() override;
private:
	Engine* m_engine;
	
};

