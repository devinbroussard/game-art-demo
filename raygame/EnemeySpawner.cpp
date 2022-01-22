#include "EnemeySpawner.h"
#include "Player.h"
#include "Transform2D.h"
#include "Enemy.h"
#include "Actor.h"
#include "HealthDisplay.h"


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
		Engine::getCurrentScene()->addActor(enemy);
		//Made a intece of healthDisplay
		HealthDisplay* enemyHealthDisplay = new HealthDisplay(10, -3, enemy);
		//added the healthDisplay to the currentScene
		Engine::getCurrentScene()->addUIElement(enemyHealthDisplay);
	}

}
