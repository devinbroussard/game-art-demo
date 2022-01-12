#include "FollowComponent.h"
#include "Actor.h"


FollowComponent::FollowComponent(const char* name, Actor* targetActor) :
	Component::Component(name)
{
	m_targetActor = targetActor;
}

MathLibrary::Vector2 FollowComponent::getMoveAxis()
{
	//Finds the target actor then gets its world Position then subtracts form its own world Position
	MathLibrary::Vector2 direction = (m_targetActor->getTransform()->getWorldPosition() - getOwner()->getTransform()->getWorldPosition());

	if (direction.getMagnitude() < 75)
		//then returns its output
		return direction.getNormalized();
	else return { 0, 0 };
}

void FollowComponent::update(float deltaTime)
{
	Component::update(deltaTime);
}
