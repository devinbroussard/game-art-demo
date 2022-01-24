#pragma once
#include "Component.h"
#include "MoveComponent.h"
#include <Vector2.h>
#include "Transform2D.h"
class Character;

class FollowComponent :
	public Component
{
public:
	//default constructor for the followComponet
	FollowComponent(const char* name, Character* targetActor);

	//gets the move Axis
	MathLibrary::Vector2 getMoveAxis();
	
	//calls update
	void update(float deltaTime) override;

private:
	Character* m_targetActor;
	bool m_hasDestination;
};

