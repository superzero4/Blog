#pragma once
#include "Color.h"
#include <vec2.hpp>
class Geometry
{
protected:

public:
	Color color;
	Geometry(Color color) :color(color) {}
	virtual void Draw() const = 0;
	static void DrawLine(glm::vec2 begin, glm::vec2 end, Color color /*= Color(1.0f, 1.0f, 0.0f)*/, int width = 1);
};


