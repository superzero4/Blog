#pragma once
#include <GL/glut.h>
#include <vec2.hpp>
class Drawing
{
public :
	void DrawLine(int xB, int yb, int xE, int yE, int width = 50);
	void DrawLine(glm::vec2 begin, glm::vec2 end, int width = 50) {
		DrawLine(begin.x, begin.y, end.x, end.y, width);
	}
};

