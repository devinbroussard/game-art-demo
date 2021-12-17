#include "InputComponent.h"
#include "Actor.h"
#include "Transform2D.h"

InputComponent::InputComponent(Actor* owner) :
	Component::Component("Input Component")
{}

MathLibrary::Vector2 InputComponent::getMoveAxis()
{
	//Get the direction of the individual axis
	float xDirection = -RAYLIB_H::IsKeyDown(KEY_A) + RAYLIB_H::IsKeyDown(KEY_D);
	float yDirection = RAYLIB_H::IsKeyDown(KEY_S) - RAYLIB_H::IsKeyDown(KEY_W);

	//Return a new vector representing the move directiodn
	return MathLibrary::Vector2(xDirection, yDirection).getNormalized();
}

void InputComponent::getAttackInput()
{

}

MathLibrary::Vector2 getForwardAxis()
{
	//Get the direction of the individual axis
	float xDirection = -RAYLIB_H::IsKeyDown(KEY_LEFT) + RAYLIB_H::IsKeyDown(KEY_RIGHT);
	float yDirection = RAYLIB_H::IsKeyDown(KEY_DOWN) - RAYLIB_H::IsKeyDown(KEY_UP);

	return MathLibrary::Vector2(xDirection, yDirection).getNormalized();
}


void InputComponent::update(float deltaTime)
{
	MathLibrary::Vector2 forwardAxis = getForwardAxis();

	if (forwardAxis.getMagnitude() > 0)
		getOwner()->getTransform()->setForward(forwardAxis);
}
