#include "Drawing.h"
#include <iostream>

void const Drawing::DrawAllGeometry(Geometry* const geometry)
{
	for (auto l : geometry->getLines())
	{
		DrawLine(l.x, l.y, 1);
	}
}

void Drawing::DrawLine(int xB, int yB, int xE, int yE, int width)
{
	// Draw a rectangle at (x, y) with size 25x25
	//std::cout << "Drawing beetween (" << xB << "," << yB << ") and (" << xE << "," << yE << ")" << std::endl;
	glColor3f(1.0f, 1.0f, 0.0f);
	for (size_t i = 0; i < width; i++)
	{
		glBegin(GL_LINES);
		glVertex2f(xB + i, yB + i);
		glVertex2f(xE + i, yE + i);
		glEnd();
	}
	glFlush();
}
