#include "MenuScene.h"
#include "UIActor.h"

void MenuScene::start()
{
<<<<<<< HEAD
	UIActor* UiActor = new UIActor(200, 200, 20, "Hi. Welcome to the game.\nstart press 1.\nTo leave press 2."  , BLACK);
=======
	UIActor* UiActor = new UIActor(20, 20, 20, "Hi. Welcome to the game.\nStart press 1.\nTo leave press 2."  , BLUE);
>>>>>>> 13e9b4f17fa901b3ab2d07a2c9778dc6e5295045
	Engine::getCurrentScene()->addUIElement(UiActor);
}

void MenuScene::update(float deltaTime)
{
	if (RAYLIB_H::IsKeyDown(KEY_ONE))
	{
		m_engine->setCurrentScene(1);
	}
	if (RAYLIB_H::IsKeyDown(KEY_TWO))
		Engine::CloseApplication();

}

void MenuScene::draw()
{
}
