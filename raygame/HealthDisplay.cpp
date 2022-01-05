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

void HealthDisplay::start()
{
	m_firstHeart = new HeartUI(-6, 0, m_owner, this);
	m_secondHeart = new HeartUI(0, 0, m_owner, this);
	m_thirdHeart = new HeartUI(6, 0, m_owner, this);

	Engine::getCurrentScene()->addActor(m_firstHeart);
	Engine::getCurrentScene()->addActor(m_secondHeart);
	Engine::getCurrentScene()->addActor(m_thirdHeart);

	Actor::start();
}

void HealthDisplay::update(float deltaTime)
{	
	std::cout << getTransform()->getWorldPosition().x << std::endl;
	std::cout << getTransform()->getWorldPosition().y << std::endl;
	Actor::update(deltaTime);
}
