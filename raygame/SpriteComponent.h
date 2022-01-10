#pragma once
#include "Component.h"
#include <raylib.h>
#include <Matrix3.h>
class Transform2D;

class SpriteComponent :
	public Component
{
public:
	//Default constructor for the SpriteComponet 
	SpriteComponent(const char* path, const char* name = "SpriteComponent");
	//secondary constructor for the Sprite Componet that takes a Textur2D pointer not a path
	SpriteComponent(Texture2D* texture, const  char* name = "SpriteComponent");
	//defaut decontructor
	~SpriteComponent() override;

	//returns the texture
	Texture2D* getTexture() { return m_texture; }
	void setTexture(Texture2D* texture);

	//returns the width and height
	int getWidth() { return m_width; }
	int getHeight() { return m_height; }

	//called update
	virtual void update(float deltaTime) override {}
	virtual void draw() override;

private:
	Texture2D* m_texture;
	int m_width;
	int m_height;
};

