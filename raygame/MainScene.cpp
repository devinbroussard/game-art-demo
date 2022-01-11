#include "MainScene.h"
#include "Actor.h"
#include "Player.h"
#include "Scene.h"
#include "Transform2D.h"
#include "HealthDisplay.h"
#include "EnemeySpawner.h"
#include "UIActor.h"
#include "MenuScene.h"
#include "Enemy.h"

void MainScene::start()
{

	RAYLIB_H::KEY_PAUSE;
	UIActor* UiActor = new UIActor(20, 20, 20, "Press z to increase scale." 
		"\nPress x to decrease scale", BLACK);
	
	Engine::getCurrentScene()->addUIElement(UiActor);

	//made the map with the load Textures
	m_map = RAYLIB_H::LoadTexture("Sprites/Map.png");
	//adds player to the scene as a actor
	Player* player = new Player(150, 150, "player", 100);
	//Initializes the player in the scene
	addActor(player);
	//adds the healthDispaly to the scene
	HealthDisplay* playerHealthDisplay = new HealthDisplay(10, -3, player);
	//initializes the player health display
	addUIElement(playerHealthDisplay);


	Enemy* enemy = new Enemy(0, 0, "Enemy", 50, player);
	HealthDisplay* enemyHealthDisplay = new HealthDisplay(10, -3, enemy);
	addActor(enemy);
	addUIElement(enemyHealthDisplay);



	//adds the spawner ot the scene 
	//EnemeySpawner* enemySpawner = new EnemeySpawner(player);
	//Initializes the enemySpawner
	//addActor(enemySpawner);
	Scene::start();

}

void MainScene::draw()
{
	RAYLIB_H::DrawTextureEx(m_map, { -200, -1350 }, 0, 3, WHITE);
	Scene::draw();
}

