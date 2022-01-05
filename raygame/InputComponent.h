#pragma once
#include "Component.h"
#include <Vector2.h>
#include <raylib.h>

class InputComponent :
	public Component
{
public:
	//default constructor of input COmponet
	InputComponent(Actor* owner);

	//gets the move Axis ...( it moves things)
	MathLibrary::Vector2 getMoveAxis();
	//gets the attack Input 
	bool getAttackInput();
	//called update
	void update(float deltaTime) override;

private:
	bool m_isAttacking;

	//These are Raylib KEys that are in the program
	RAYLIB_H::KeyboardKey m_up = RAYLIB_H::KeyboardKey::KEY_W;
	RAYLIB_H::KeyboardKey m_left = RAYLIB_H::KeyboardKey::KEY_A;
	RAYLIB_H::KeyboardKey m_down = RAYLIB_H::KeyboardKey::KEY_S;
	RAYLIB_H::KeyboardKey m_right = RAYLIB_H::KeyboardKey::KEY_D;
	RAYLIB_H::KeyboardKey m_meleeSwing = RAYLIB_H::KeyboardKey::KEY_SPACE;
};

