#pragma once
#include<SDL_opengl.h>
class Sprite
{
public:
	Sprite();
	~Sprite();
	void init(float x, float y, float height, float width);
	void draw();
private:
	float x;
	float y;
	float height;
	float width;
	GLuint vboId;
};

