#pragma once
#include <gl/glut.h>
class Color
{
public:
	GLfloat r, g, b;
	Color(GLfloat r, GLfloat g, GLfloat b) {
		this->r = r;
		this->g = g;
		this->b = b;
	}
	Color() {
		this->r = .5f;
		this->g = .5f;
		this->b = .5f;
	}
	GLfloat operator[](int i) {
		switch (i)
		{
		case 0:
			return r;
		case 1:
			return g;
		case 2:
			return b;
		default:
			throw "OutOfRange";
		}
	}
};

