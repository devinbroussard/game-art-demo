#include "EnemeySpawner.h"
#include "Player.h"
#include "Transform2D.h"
#include "Enemy.h"
#include "Actor.h"



void EnemeySpawner::update(float deltaTime)
{
	//Compares the enemy counter to the number on the right hand side
	if (Enemy::m_enemyCount < 1)
	{
		//Initializes a new Enemy with its stats...
		Enemy* enemy = new Enemy(100, 100, "enemy", 60, 10, m_player);
		//..Sets its scale...
		enemy->getTransform()->setScale({ 50, 50 });
		//...adds the enemy to the scene
		Engine::getCurrentScene()->addActor(enemy);
	}

}
