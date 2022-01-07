#include "MainScene.h"
#include "Actor.h"
#include "Player.h"
#include "Scene.h"
#include "Transform2D.h"
#include <iostream>
#include "EnemeySpawner.h"
#include "UIActor.h"

void MainScene::start()
{
	UIActor* UiActor = new UIActor(200, 200, 200, "Press x to fight"
		"Press y to leave", WHITE);

	Engine::getCurrentScene()->addUIElement(UiActor);

	//made the map with the load Textures
	m_map = RAYLIB_H::LoadTexture("Sprites/Map.png");
	//Initializes the player in the scene
	Player* player = new Player(200, 200, "player", 100, 10);
	//scales the player
	player->getTransform()->setScale({ 50, 50 });
	//adds player to the scene as a actor
	addActor(player);

	//Initializes the enemySpawner
	EnemeySpawner* enemySpawner = new EnemeySpawner(player);
	//adds the spawner ot the scene as a actor
	addActor(enemySpawner);

}

void MainScene::draw()
{
	RAYLIB_H::DrawTextureEx(m_map, { -200, -1350 }, 0, 3, WHITE);
	Scene::draw();
}

