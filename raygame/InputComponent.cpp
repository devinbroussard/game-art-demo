#include "InputComponent.h"
#include "Actor.h"
#include "Transform2D.h"

InputComponent::InputComponent(Actor* owner) :
	Component::Component("Input Component")
{}

MathLibrary::Vector2 InputComponent::getMoveAxis()
{
	//Get the direction of the individual axis
	float xDirection = -RAYLIB_H::IsKeyDown(m_left) + RAYLIB_H::IsKeyDown(m_right);
	float yDirection = RAYLIB_H::IsKeyDown(m_down) - RAYLIB_H::IsKeyDown(m_up);

	//Return a new vector representing the move directiodn
	return MathLibrary::Vector2(xDirection, yDirection).getNormalized();
}

MathLibrary::Vector2 InputComponent::getForwardAxis()
{
	//Get the direction of the individual axis
	float xDirection = -RAYLIB_H::IsKeyDown(m_lookLeft) + RAYLIB_H::IsKeyDown(m_lookRight);
	float yDirection = RAYLIB_H::IsKeyDown(m_lookDown) - RAYLIB_H::IsKeyDown(m_lookUp);

	return MathLibrary::Vector2(xDirection, yDirection).getNormalized();
}

bool InputComponent::getAttackInput()
{
	return IsKeyDown(m_meleeSwing);
}

void InputComponent::update(float deltaTime)
{
	MathLibrary::Vector2 forwardAxis = getForwardAxis();

	if (forwardAxis.getMagnitude() > 0)
		getOwner()->getTransform()->setForward(forwardAxis);
}
