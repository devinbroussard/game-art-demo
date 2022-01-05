#include "MoveComponent.h"
#include "Actor.h"
#include "Component.h"
#include "Character.h"


MoveComponent::MoveComponent(const char* name) : Component::Component(name)
{
	m_maxSpeed = 0;
	m_velocity = MathLibrary::Vector2(0, 0);
}

void MoveComponent::update(float deltaTime)
{
	MathLibrary::Vector2 oldPosition = getOwner()->getTransform()->getLocalPosition();
	MathLibrary::Vector2 forward = getOwner()->getTransform()->getForward();

	//Add the new velocity to the old posiiton to get the new position
	MathLibrary::Vector2 newPosition = MathLibrary::Vector2((oldPosition.x + (m_velocity.x * deltaTime)),
		(oldPosition.y + (m_velocity.y * deltaTime)));

	if (newPosition.x > m_maxX)
		newPosition.x = m_maxX;
	if (newPosition.y > m_maxY)
		newPosition.y = m_maxY;
	if (newPosition.x < m_minX)
		newPosition.x = m_minX;
	if (newPosition.y < m_minY)
		newPosition.y = m_minY;
		
			
	if (newPosition.getMagnitude() > 0)
		getOwner()->getTransform()->setLocalPosition(newPosition);
}