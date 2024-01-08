#pragma once
#include <vector>
#include <vec2.hpp>
#include "Geometry.h"
class ClosedLineSequence : public Geometry
{
private:
	std::vector<glm::vec2> points;
	glm::vec2 lastPoint = glm::vec2(-1, -1);
	bool closed = false;
public:
	ClosedLineSequence(glm::vec2 begin,Color color) : Geometry(color) {
		AddPoint(begin);
	}
	void AddPoint(glm::vec2 newPoint);
	void EndPolygon();
	const std::vector<glm::vec2> getPoints() { return points; }
	const bool isClosed() { return closed; }

	// Inherited via Geometry
	virtual void Draw() const override;
};
