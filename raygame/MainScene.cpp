#include "MainScene.h"
#include "Actor.h"
#include "Player.h"
#include "Scene.h"
#include "Transform2D.h"
#include "HealthDisplay.h"
#include "EnemeySpawner.h"
#include "UIActor.h"
#include "MenuScene.h"

void MainScene::start()
{

	UIActor* UiActor = new UIActor(20, 20, 20, "Press z to increase scale." 
		"\nPress x to decrease scale", BLACK);
	
	Engine::getCurrentScene()->addUIElement(UiActor);

	//made the map with the load Textures
	m_map = RAYLIB_H::LoadTexture("Sprites/Map.png");

	Player* player = new Player(150, 150, "player", 100);
	Enemy* enemy = new Enemy(10, 100, "enemy", 60, player);

	addActor(player);

	HealthDisplay* playerHealthDisplay = new HealthDisplay(24, 22, player);
	addUIElement(playerHealthDisplay);
	//EnemeySpawner* enemySpawner = new EnemeySpawner(player);
	//addActor(enemySpawner);
	//adds the spawner ot the scene as a actor
	//Initializes the enemySpawner
	//adds player to the scene as a actor
	//scales the player
	//Initializes the player in the scene
}

void MainScene::draw()
{
	RAYLIB_H::DrawTextureEx(m_map, { -200, -1350 }, 0, 3, WHITE);
	Scene::draw();
}

