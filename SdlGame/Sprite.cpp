#include "Sprite.h"
#include<SDL_opengl_glext.h>
Sprite::Sprite():vboId(0)
{
}

Sprite::~Sprite()
{
	if (vboId) {
		glDeleteBuffers(1, &vboId);
	}
}

void Sprite::init(float x, float y, float height, float width)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;

	if (vboId == 0) {
		glGenBuffers(1, &vboId);
	}
	/**
	B════A
	║    ║
	C════D
	*/
	float vertexData[2 * 3 * 2] = {
		/*A*/x + width-0.1 ,y + height  /*B*/,x, y + height,/*C*/x ,y,//
		/*C*/x ,y  /*A*/,x +width-0.3,y,/*D*/ x+ width ,y+height//
	};
	glBindBuffer(GL_ARRAY_BUFFER, vboId);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData),vertexData,GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Sprite::draw()
{
	glBindBuffer(GL_ARRAY_BUFFER, vboId);

	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);

	glDrawArrays(GL_TRIANGLES, 0, 6);

	glDisableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
