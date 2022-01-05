#include "MainScene.h"
#include "Actor.h"
#include "Player.h"
#include "Enemy.h"
#include "Scene.h"
#include "Transform2D.h"
#include "HealthDisplay.h"

void MainScene::start()
{
	m_map = RAYLIB_H::LoadTexture("Sprites/Map.png");

	Player* player = new Player(200, 200, "player", 100, 10);
	//Enemy* enemy = new Enemy(10, 100, "enemy", 60, 10, player);

	HealthDisplay* playerHealthDisplay = new HealthDisplay(0, 0, player);
	
	player->getTransform()->setScale({ 50, 50 });
	//enemy->getTransform()->setScale({ 50, 50 });

	addActor(player);
	//addActor(enemy);
	
	addUIElement(playerHealthDisplay);
}

void MainScene::draw()
{
	RAYLIB_H::DrawTextureEx(m_map, { -200, -1350 }, 0, 3, WHITE);
	Scene::draw();
}
