#pragma once
#include "Geometry.h"
#include <vec2.hpp>
class Line : public Geometry
{
private:
	glm::vec<2, glm::vec2> points;
public:
	Line(glm::vec<2, glm::vec2> points,Color color) : Geometry(color) {
		this->points = points;
	}
	Line(glm::vec2 begin, glm::vec2 end,Color color) : Line(glm::vec<2, glm::vec2>(begin, end),color) {
	}
	// Inherited via Geometry
	virtual void Draw() const override {
		DrawLine(points.x, points.y,color, 1);
	}
};

