#include "HealthDisplay.h"
#include "HeartUI.h"
#include "Character.h"
#include "Engine.h"
#include "Transform2D.h"
#include "Engine.h"

HealthDisplay::HealthDisplay(float x, float y, Character* owner) : 
	Actor(x, y, "HealthDisplay")
{
	m_owner = owner;
	m_owner->getTransform()->addChild(getTransform());
}

HealthDisplay::~HealthDisplay()
 {
	Engine::destroy(this);
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
	Engine::getCurrentScene()->addUIElement(m_firstHeart);
	m_firstHeart->start();
	Engine::getCurrentScene()->addUIElement(m_secondHeart);
	m_secondHeart->start();
	Engine::getCurrentScene()->addUIElement(m_thirdHeart);
	m_thirdHeart->start();

	Actor::start();
}

/// <summary>
/// Updates the health icons
/// </summary>
/// <param name="deltaTime"></param>
void HealthDisplay::update(float deltaTime)
{	
	Actor::update(deltaTime);
	checkHealth(deltaTime);
}

/// <summary>
/// Updates the heart icons depending on the character's health
/// </summary>
/// <param name="deltaTime"></param>
void HealthDisplay::checkHealth(float deltaTime)
{
	if (!m_owner->getHealthComponent())//if nullpointer happes return
		return;
	//turns the hearts to black
	if (m_owner->getHealthComponent()->getHealth() < 3)
		m_thirdHeart->killHeart(deltaTime);
	if (m_owner->getHealthComponent()->getHealth() < 2)
		m_secondHeart->killHeart(deltaTime);
	if (m_owner->getHealthComponent()->getHealth() < 1)
	{
		m_firstHeart->killHeart(deltaTime);

		m_deathTimeTracker += deltaTime;
		if (m_deathTimeTracker > 5) {
			Engine::getCurrentScene()->removeUIElement(this);
		}

	}
		
}
