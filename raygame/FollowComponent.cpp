#include "FollowComponent.h"
#include "Actor.h"


FollowComponent::FollowComponent(const char* name, Actor* targetActor) :
	Component::Component(name)
{
	m_targetActor = targetActor;
}

MathLibrary::Vector2 FollowComponent::getMoveAxis()
{
	MathLibrary::Vector2 direction = (m_targetActor->getTransform()->getWorldPosition() - getOwner()->getTransform()->getWorldPosition()).getNormalized();
	return direction;
}

void FollowComponent::update(float deltaTime)
{
	Component::update(deltaTime);
}
