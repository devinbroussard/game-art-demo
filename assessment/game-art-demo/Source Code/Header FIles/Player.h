#pragma once
#include "Character.h"
#include "AABBCollider.h"
#include "Engine.h"
class InputComponent;

class Player :
	public Character
{
public:
	Player(float x, float y, const char* name, float speed);
	~Player() {};

	//Made the getinput componet to return the input componet
	InputComponent* getInputComponent() { return m_inputComponent; }

	//defalt start
	void start() override;
	//defalt update
	void update(float deltaTime) override;
	void  onCollision(Actor* other);
private:
	
	InputComponent* m_inputComponent;
	AABBCollider* m_aabbCollider;
	Player* m_player;
};

