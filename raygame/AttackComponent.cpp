#include "AttackComponent.h"
#include "Component.h"
#include "CircleCollider.h"
#include <raylib.h>
#include "Transform2D.h"
#include "Actor.h"
#include "Character.h"
#include "MoveComponent.h"
#include "Engine.h"

AttackComponent::AttackComponent(float fps, int attackFrames)
{
	m_fps = fps;
	m_attackFrames = attackFrames;
	

	m_attackActor = new Actor(0, 0, "Attack");
	CircleCollider* circleCollider = new CircleCollider(120, m_attackActor);
	m_attackActor->setCollider(circleCollider);
}

void AttackComponent::start()
{

}

void AttackComponent::update(float deltaTime)
{
	//Adds deltatime to the time tracker
	m_timeTracker += deltaTime;


	//If the character is atacking...
	if (m_isAttacking)
	{
		//If the attack hasn't been started, spawn the attack actor, and set started to true
		if (!m_attackStarted)
		{
			if (getCharacterOwner()->getMoveComponent()->getMovedRightLast())
				m_attackActor->getTransform()->setWorldPostion({ getOwner()->getTransform()->getWorldPosition().x + 40,
					getOwner()->getTransform()->getWorldPosition().y + 30 });

			if (!getCharacterOwner()->getMoveComponent()->getMovedRightLast())
				m_attackActor->getTransform()->setWorldPostion({ getOwner()->getTransform()->getWorldPosition().x + 10,
					getOwner()->getTransform()->getWorldPosition().y + 30 });

			Engine::getCurrentScene()->addActor(m_attackActor);
			m_attackStarted = true;
		}
		//else
		//{

		//	if (getCharacterOwner()->getMoveComponent()->getMovedRightLast())
		//		DrawCircleLines(getOwner()->getTransform()->getWorldPosition().x + 40, getOwner()->getTransform()->getWorldPosition().y + 30, 30, RAYLIB_H::BLACK);

		//	else if(!getCharacterOwner()->getMoveComponent()->getMovedRightLast())
		//		DrawCircleLines(getOwner()->getTransform()->getWorldPosition().x + 10, getOwner()->getTransform()->getWorldPosition().y + 30, 30, RAYLIB_H::BLACK);
		//}
	}
	//If the attack has ended, and has already been started, remove the actor from the scene, and set started to false
	else if (m_attackStarted)
	{ 
		m_attackStarted = false;
		Engine::getCurrentScene()->removeActor(m_attackActor);
		m_timeTracker = 0;
	}

	//m_isAttacking = false;
}
