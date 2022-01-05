#include "InputComponent.h"
#include "Actor.h"
#include "Transform2D.h"

InputComponent::InputComponent(Actor* owner) :
	Component::Component("Input Component")
{}

//get Move Axis allow for movement on the x and y axis with the wasd keys.
MathLibrary::Vector2 InputComponent::getMoveAxis()
{
	if (!m_isAttacking)
	{
		//Get the direction of the individual axis
		float xDirection = -RAYLIB_H::IsKeyDown(m_left) + RAYLIB_H::IsKeyDown(m_right);
		float yDirection = RAYLIB_H::IsKeyDown(m_down) - RAYLIB_H::IsKeyDown(m_up);

		//Return a new vector representing the move directiodn
		return MathLibrary::Vector2(xDirection, yDirection).getNormalized();
	}
		
	return MathLibrary::Vector2(0, 0);
}

bool InputComponent::getAttackInput()
{
	return m_isAttacking;
}

void InputComponent::update(float deltaTime)
{
	//if the key is = to the meleeswing
	if (IsKeyPressed(m_meleeSwing))
		m_isAttacking = true;//set the bool to true and continue
	
	//make the forwardAxis = to the move Axis
	MathLibrary::Vector2 forwardAxis = getMoveAxis();

	//if the forwardAxis after you get its magnitude is bigger than 0
	if (forwardAxis.getMagnitude() > 0)
		getOwner()->getTransform()->setForward(forwardAxis);//set the forward(that is currently active)
															//	to the forward Axis ( that is being made)
}


