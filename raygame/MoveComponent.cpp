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

	//Add the new velocity to the old posiiton to get the new position
	MathLibrary::Vector2 newPosition = MathLibrary::Vector2((oldPosition.x + (m_velocity.x * deltaTime)),
		(oldPosition.y + (m_velocity.y * deltaTime)));


	/// <summary>
	/// This is meant to make a boundary that forces the player in and keeps them there 
	/// </summary>
	/// <param name="deltaTime"></param>
	//if the new Position of x is greater than the maxX
	if (newPosition.x > m_maxX)
		newPosition.x = m_maxX;//if it is then set the  x to the max X
	//if the new Position of y is greater than the maxy
	if (newPosition.y > m_maxY)//if it is then set the  y to the max Y
		newPosition.y = m_maxY;
	//if the new Position of x is less than the minX
	if (newPosition.x < m_minX)//if it is then set the  x to the min X
		newPosition.x = m_minX;
	//if the new Position of y is less than the minY
	if (newPosition.y < m_minY)//if it is then set the  y to the min y
		newPosition.y = m_minY;
		
	//Gets the new Posistion and gets it magnitude then compares if its greater than 0
	if (newPosition.getMagnitude() > 0)//if yes then set The local Position by the new Position
		getOwner()->getTransform()->setLocalPosition(newPosition);
}