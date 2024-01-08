#pragma once
#include <GL/glut.h>
#include <vec2.hpp>
#include <string>
#include <vector>
#include "Geometry.h"
class Drawing
{
private:
	GLuint id;
	std::vector<Geometry*> geometries;
public:
	void const DrawAllGeometry();

	void DrawImage(bool forceWindow = true);
	void LoadBackground(std::string path) {
		throw "Not implemented, require external libraries";
		id = 0;
	}
	int AddGeometry(Geometry* g) {
		geometries.push_back(g);
		return geometries.size() - 1;
	}
};

