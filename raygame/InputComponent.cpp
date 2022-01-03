#include "InputComponent.h"
#include "Actor.h"
#include "Transform2D.h"

InputComponent::InputComponent(Actor* owner) :
	Component::Component("Input Component")
{}

//get Move Axis allow for movement on the x and y axis with the wasd keys.
MathLibrary::Vector2 InputComponent::getMoveAxis()
{
	//Get the direction of the individual axis
	float xDirection = -RAYLIB_H::IsKeyDown(m_left) + RAYLIB_H::IsKeyDown(m_right);
	float yDirection = RAYLIB_H::IsKeyDown(m_down) - RAYLIB_H::IsKeyDown(m_up);

	//Return a new vector representing the move directiodn
	return MathLibrary::Vector2(xDirection, yDirection).getNormalized();
}

//get Forward Axis allow for the rotation of the player on the xy and the yx axis
MathLibrary::Vector2 InputComponent::getForwardAxis()
{
	//Get the direction of the individual axis
	float xDirection = -RAYLIB_H::IsKeyDown(m_lookLeft) + RAYLIB_H::IsKeyDown(m_lookRight);
	float yDirection = RAYLIB_H::IsKeyDown(m_lookDown) - RAYLIB_H::IsKeyDown(m_lookUp);

	return MathLibrary::Vector2(xDirection, yDirection).getNormalized();
}

bool InputComponent::getAttackInput()
{
	bool attackKey = RAYLIB_H::IsKeyDown(m_attackKey);

	return attackKey;
}

void InputComponent::update(float deltaTime)
{
	MathLibrary::Vector2 forwardAxis = getForwardAxis();

	if (forwardAxis.getMagnitude() > 0 )
		getOwner()->getTransform()->setForward(forwardAxis);
}


