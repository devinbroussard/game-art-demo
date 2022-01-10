#include "MenuScene.h"
#include "UIActor.h"
#include "MainScene.h"

void MenuScene::start()
{

	UIActor* UiActor = new UIActor(20, 20, 20, "Hi. Welcome to the game.\nstart press u.\nTo leave press y.", BLACK);

	Engine::getCurrentScene()->addUIElement(UiActor);


}

void MenuScene::update(float deltaTime)
{
	if (RAYLIB_H::IsKeyDown(KEY_U))
		m_engine->setCurrentScene(1);

	if (RAYLIB_H::IsKeyDown(KEY_Y))
		Engine::CloseApplication();

}

void MenuScene::draw()
{
	Scene::draw();
}
