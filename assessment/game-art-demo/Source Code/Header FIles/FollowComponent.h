#pragma once
#include "Component.h"
#include "MoveComponent.h"
#include <Vector2.h>
#include "Transform2D.h"



class FollowComponent :
	public Component
{
public:
	//default constructor for the followComponet
	FollowComponent(const char* name, Actor* targetActor);

	//gets the move Axis
	MathLibrary::Vector2 getMoveAxis();
	
	//calls update
	void update(float deltaTime) override;

private:
	Actor* m_targetActor;
	MoveComponent* m_moveComponet;

};

