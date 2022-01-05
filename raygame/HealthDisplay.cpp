#include "HealthDisplay.h"
#include "HeartUI.h"
#include "Character.h"
#include "Engine.h"
#include "Transform2D.h"
#include <iostream>

HealthDisplay::HealthDisplay(float x, float y, Character* owner) : 
	Actor(x, y, "HealthDisplay")

{
	m_owner = owner;
	m_owner->getTransform()->addChild(getTransform());
}

/// <summary>
/// Called whenever the actor is added to the scene
/// </summary>
void HealthDisplay::start()
{
	//Initializing heart icons
	m_firstHeart = new HeartUI(-6, 0, m_owner, this);
	m_secondHeart = new HeartUI(0, 0, m_owner, this);
	m_thirdHeart = new HeartUI(6, 0, m_owner, this);

	//Adding heart icons to scene and calling their start functions
	Engine::getCurrentScene()->addActor(m_firstHeart);
	m_firstHeart->start();
	Engine::getCurrentScene()->addActor(m_secondHeart);
	m_secondHeart->start();
	Engine::getCurrentScene()->addActor(m_thirdHeart);
	m_thirdHeart->start();

	Actor::start();
}

void HealthDisplay::update(float deltaTime)
{	
	Actor::update(deltaTime);
}

void HealthDisplay::checkHealth()
{
	if (m_owner->getHealth() < 3)
		m_thirdHeart->killHeart();
	if (m_owner->getHealth() < 2)
		m_secondHeart->killHeart();
	if (m_owner->getHealth() < 1)
		m_firstHeart->killHeart();
}
