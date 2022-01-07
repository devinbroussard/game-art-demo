#pragma once
#include "Scene.h"
#include <raylib.h>


class MenuScene :
	public Scene
{
public:
	void start() override;
	void update(float deltaTime) override;
private:
	Scene* m_sceneUI;
	
	
};

