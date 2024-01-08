#include "Geometry.h"

void Geometry::DrawLine(glm::vec2 begin, glm::vec2 end, Color color, int width)
{
	// Draw a rectangle at (x, y) with size 25x25
	//std::cout << "Drawing beetween (" << xB << "," << yB << ") and (" << xE << "," << yE << ")" << std::endl;
	glColor3f(color.r,color.g,color.b);
	for (size_t i = 0; i < width; i++)
	{
		glBegin(GL_LINES);
		glVertex2f(begin.x + i, begin.y + i);
		glVertex2f(end.x + i, end.y + i);
		glEnd();
	}
	glFlush();
}
