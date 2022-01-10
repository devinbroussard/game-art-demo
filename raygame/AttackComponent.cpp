#include "AttackComponent.h"
#include "Component.h"
#include "CircleCollider.h"
#include <raylib.h>
#include "Transform2D.h"
#include "Actor.h"
#include "Character.h"
#include "MoveComponent.h"

AttackComponent::AttackComponent(float fps, int attackFrames)
{
	m_fps = fps;
	m_attackFrames = attackFrames;
}

void AttackComponent::update(float deltaTime)
{
	if (m_isAttacking)
	{
		if (m_timeTracker < ((1 / m_fps) * m_attackFrames))
		{	
			if (getCharacterOwner()->getMoveComponent()->getMovedRightLast())
			{
				DrawCircleLines(getOwner()->getTransform()->getWorldPosition().x, getOwner()->getTransform()->getWorldPosition().y, 30, RAYLIB_H::BLACK);
				CircleCollider* circleCollider = new CircleCollider(30, getOwner());
			}
		}
		else if (m_timeTracker > m_fps) m_timeTracker = 0;
	}

	m_isAttacking = false;
}
