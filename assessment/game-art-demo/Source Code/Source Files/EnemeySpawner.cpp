#include "EnemeySpawner.h"
#include "Player.h"
#include "Transform2D.h"
#include "Enemy.h"
#include "Actor.h"


/// <summary>
/// Spawns another enemy if all of the enemies in the scene have been slain
/// </summary>
/// <param name="deltaTime"></param>
void EnemeySpawner::update(float deltaTime)
{
	
	//Compares the enemy counter to the number on the right hand side
	if (Enemy::m_enemyCount < 1)
	{
		Enemy::m_enemyCount++;
		//Initializes a new Enemy with its stats...
		Enemy* enemy = new Enemy(200, 200, "enemy", 20, m_player );
		enemy->start();


		//...adds the enemy to the scene
		Engine::getCurrentScene()->addActor(enemy);
	}

}
