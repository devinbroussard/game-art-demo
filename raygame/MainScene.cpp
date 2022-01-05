#include "MainScene.h"
#include "Actor.h"
#include "Player.h"
#include "Enemy.h"
#include "Scene.h"
#include "Transform2D.h"
#include <iostream>
#include "EnemeySpawner.h"

void MainScene::start()
{
	m_map = RAYLIB_H::LoadTexture("Sprites/Map.png");
	Player* player = new Player(200, 200, "player", 100, 10);

	player->getTransform()->setScale({ 50, 50 });
	addActor(player);

	EnemeySpawner* enemySpawner = new EnemeySpawner(player);
	addActor(enemySpawner);
}

void MainScene::draw()
{
	RAYLIB_H::DrawTextureEx(m_map, { -200, -1350 }, 0, 3, WHITE);
	Scene::draw();
}

