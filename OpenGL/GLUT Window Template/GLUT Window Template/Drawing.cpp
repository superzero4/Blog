#include "Drawing.h"
#include <iostream>

void const Drawing::DrawAllGeometry()
{
	for (auto g : geometries) {
		g->Draw();
	}
}

void DrawImage(bool forceScale) {
	/*glBindTexture(GL_TEXTURE_2D, id);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex2f(-1, -1);
	glTexCoord2f(1, 0); glVertex2f(1, -1);
	glTexCoord2f(1, 1); glVertex2f(1, 1);
	glTexCoord2f(0, 1); glVertex2f(-1, 1);
	glEnd();*/
}
