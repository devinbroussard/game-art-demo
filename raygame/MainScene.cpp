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

	UIActor* UiActor = new UIActor(20, 20, 20, "Press z to increase scale." 
		"\nPress x to decrease scale" "\nPress c to go to standard scale" "\nPress e to kill the player" "\nPress ESC to leave");
	
	Engine::getCurrentScene()->addUIElement(UiActor);

	//made the map with the load Textures
	m_map = RAYLIB_H::LoadTexture("Sprites/Map.png");
	//adds player to the scene as a actor
	Player* player = new Player(300, 300, "player", 100);
	//Initializes the player in the scene
	addActor(player);
	//adds the healthDispaly to the scene
	HealthDisplay* playerHealthDisplay = new HealthDisplay(10, -3, player);
	//initializes the player health display
	addUIElement(playerHealthDisplay);
	//made a intece of enemy spawner but made it take in a player
	EnemeySpawner* enemySpawner = new EnemeySpawner(player);
	//Initializes the enemySpawner
	addActor(enemySpawner);

	Scene::start();

}

void MainScene::draw()
{
	RAYLIB_H::DrawTextureEx(m_map, { -200, -1350 }, 0, 3, WHITE);
	Scene::draw();
}

