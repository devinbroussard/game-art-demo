#include "MainScene.h"
#include "Actor.h"
#include "Player.h"
#include "Enemy.h"
#include "MeleeWeaponActor.h"
#include "Scene.h"
#include "Transform2D.h"
#include <raylib.h>

void MainScene::start()
{
	Player* player = new Player(200, 200, "player", 100, 10);
	MeleeWeaponActor* bat = new MeleeWeaponActor(player);

	Enemy* enemy = new Enemy(10, 100, "enemy", 60, 10, player);
	player->getTransform()->setScale({ 50, 50 });
	enemy->getTransform()->setScale({ 50, 50 });

	addActor(player);
	addActor(enemy);
	addActor(bat);
}

void MainScene::draw()
{
	RAYLIB_H::DrawTextureEx(RAYLIB_H::LoadTexture("Sprites/Map.aseprite"), { 0, 0 }, 0, 1, WHITE);
	Scene::draw();
}
