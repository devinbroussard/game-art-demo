#include "MenuScene.h"
#include "UIActor.h"

void MenuScene::start()
{
	//Adds the text menu to the scene
	UIActor* UiActor = new UIActor(200, 200, 20, "Hi. Welcome to the game.\nstart press 1.\nTo leave press 2.", BLACK);
	Engine::getCurrentScene()->addUIElement(UiActor);
}

/// <summary>
/// Updates the scene depending on the input given
/// </summary>
/// <param name="deltaTime"></param>
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
{}
