#pragma once
#include <GL/glut.h>
#include <vec2.hpp>
#include "Geometry.h"
#include <string>
class Drawing
{
private:
	GLuint id;
public:
	void const DrawAllGeometry(Geometry* const geometry);
	void DrawLine(int xB, int yb, int xE, int yE, int width = 1);
	void DrawLine(glm::vec2 begin, glm::vec2 end, int width = 1) {
		DrawLine(begin.x, begin.y, end.x, end.y, width);
	}
	void DrawImage( bool forceWindow = true);
	void LoadBackground(std::string path) {
		throw "Not implemented, require external libraries";
		id = 0;
	}
};

