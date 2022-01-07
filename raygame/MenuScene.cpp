#include "MenuScene.h"
#include "Engine.h"
#include "UIActor.h"

void MenuScene::start()
{

	UIActor* UiActor = new UIActor(20, 20, 20, "Press x to fight"
		"Press y to leave", BLACK);

	Engine::getCurrentScene()->addUIElement(UiActor);

	if (RAYLIB_H::IsKeyDown(KEY_X))
		Engine::setCurrentScene(2);

	if (RAYLIB_H::IsKeyDown(KEY_Y))
		Engine::CloseApplication();
}

void MenuScene::update(float deltaTime)
{


}
