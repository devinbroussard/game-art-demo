#pragma once
#include "Component.h"
#include "MoveComponent.h"
#include <Vector2.h>
#include "Transform2D.h"



class FollowComponent :
	public Component
{
public:
	FollowComponent(const char* name, Actor* targetActor);

	/// <summary>
	/// Set the current speed and direction of this actor
	/// </summary>
	/// <param name="velocity"></param>

	MathLibrary::Vector2 getMoveAxis();

	void update(float deltaTime) override;

private:
	Actor* m_targetActor;
	MoveComponent* m_moveComponet;

};

