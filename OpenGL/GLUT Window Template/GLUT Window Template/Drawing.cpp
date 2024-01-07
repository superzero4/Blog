#include "Drawing.h"
#include <iostream>

void const Drawing::DrawAllGeometry(Geometry* const geometry)
{
	//DrawImage(true);
	for (auto l : geometry->getFreeLines())
	{
		DrawLine(l.x, l.y, 1);
	}
	for (auto l : geometry->getPolygons())
	{
		auto points = l->getPoints();
		for (size_t i = 0; i < points.size() - 1; i++)
			DrawLine(points[i], points[i + 1]);
		if (l->isClosed())
			DrawLine(points[points.size() - 1], points[0]);
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
void Drawing::DrawImage(bool forceScale) {
	glBindTexture(GL_TEXTURE_2D, id);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex2f(-1, -1);
	glTexCoord2f(1, 0); glVertex2f(1, -1);
	glTexCoord2f(1, 1); glVertex2f(1, 1);
	glTexCoord2f(0, 1); glVertex2f(-1, 1);
	glEnd();
}
