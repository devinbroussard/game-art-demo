#pragma once
#include "Component.h"
#include <raylib.h>
#include <Matrix3.h>
class Transform2D;

class SpriteComponent :
	public Component
{
public:
	SpriteComponent(const char* path, const char* name = "SpriteComponent");
	SpriteComponent(Texture2D* texture, const  char* name = "SpriteComponent");
	~SpriteComponent() override;

	Texture2D* getTexture() { return m_texture; }
	void setTexture(Texture2D* texture) { m_texture = texture; }
	void setTexture(const char* path) { m_texture = &RAYLIB_H::LoadTexture(path); }

	int getWidth() { return m_width; }
	int getHeight() { return m_height; }

	virtual void update(float deltaTime) override {}
	virtual void draw() override;

private:
	Texture2D* m_texture;
	int m_width;
	int m_height;
};

