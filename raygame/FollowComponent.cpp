#include "FollowComponent.h"
#include "Actor.h"
#include "Character.h"


FollowComponent::FollowComponent(const char* name, Character* targetActor) :
	Component::Component(name)
{
	m_targetActor = targetActor;
	m_hasDestination = true;
}

MathLibrary::Vector2 FollowComponent::getMoveAxis()
{
	if (m_hasDestination)
		if (m_targetActor->getHealthComponent()->getHealth() <= 0 )
			m_hasDestination = false;

	if (m_hasDestination)
	{
		//Finds the target actor then gets its world Position then subtracts form its own world Position
		MathLibrary::Vector2 direction = (m_targetActor->getTransform()->getWorldPosition() - getOwner()->getTransform()->getWorldPosition());

		if (direction.getMagnitude() > 5)
			//then returns its output
			return direction.getNormalized();
	}
	return { 0, 0 };
}

void FollowComponent::update(float deltaTime)
{
	Component::update(deltaTime);
}
