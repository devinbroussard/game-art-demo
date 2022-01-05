#pragma once
#include "Character.h"
#include "AABBCollider.h"
class InputComponent;

class Player :
	public Character
{
public:
	Player(float x, float y, const char* name, float speed, int maxHealth);
	~Player() {};

	InputComponent* getInputComponent() { return m_inputComponent; }

	void start() override;
	void update(float deltaTime) override;
	void  onCollision(Actor* other);
private:
	InputComponent* m_inputComponent;
	AABBCollider* m_aabbCollider;
};

