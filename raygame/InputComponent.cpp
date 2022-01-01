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

bool InputComponent::getAttackInput()
{
	return m_isAttacking;
}

void InputComponent::update(float deltaTime)
{
	MathLibrary::Vector2 forwardAxis = getMoveAxis();

	if (forwardAxis.getMagnitude() > 0)
		getOwner()->getTransform()->setForward(forwardAxis);

	if (IsKeyPressed(m_meleeSwing))
		m_isAttacking = true;
}
