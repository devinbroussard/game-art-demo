#pragma once
#include "Component.h"
#include <Vector2.h>
#include <raylib.h>

class InputComponent :
	public Component
{
public:
	InputComponent(Actor* owner);

	MathLibrary::Vector2 getMoveAxis();
	bool getAttackInput();
	void update(float deltaTime) override;
	MathLibrary::Vector2 getForwardAxis();

private:

	//movment Keys that are on the x and the y...
	RAYLIB_H::KeyboardKey m_forward = RAYLIB_H::KeyboardKey::KEY_W;
	RAYLIB_H::KeyboardKey m_left = RAYLIB_H::KeyboardKey::KEY_A;
	RAYLIB_H::KeyboardKey m_down = RAYLIB_H::KeyboardKey::KEY_S;
	RAYLIB_H::KeyboardKey m_right = RAYLIB_H::KeyboardKey::KEY_D;

	//the rotation keys that rotate the player...
	RAYLIB_H::KeyboardKey m_lookUp = RAYLIB_H::KeyboardKey::KEY_UP;
	RAYLIB_H::KeyboardKey m_lookLeft = RAYLIB_H::KeyboardKey::KEY_LEFT;
	RAYLIB_H::KeyboardKey m_lookDown = RAYLIB_H::KeyboardKey::KEY_DOWN;
	RAYLIB_H::KeyboardKey m_lookRight = RAYLIB_H::KeyboardKey::KEY_RIGHT;

	//this is the attack key
	RAYLIB_H::KeyboardKey m_attackKey = RAYLIB_H::KeyboardKey::KEY_SPACE;

};

