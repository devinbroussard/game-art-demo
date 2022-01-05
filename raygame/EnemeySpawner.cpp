#include "EnemeySpawner.h"
#include "Player.h"
#include "Transform2D.h"
#include "Enemy.h"
#include "Actor.h"



void EnemeySpawner::update(float deltaTime)
{
	if (Enemy::m_enemyCount < 1)
	{
		Enemy* enemy = new Enemy(100, 100, "enemy", 60, 10, m_player);
		enemy->getTransform()->setScale({ 50, 50 });
		Engine::getCurrentScene()->addActor(enemy);
	}

}
