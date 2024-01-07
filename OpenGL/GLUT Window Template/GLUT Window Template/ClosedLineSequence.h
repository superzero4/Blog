#pragma once
#include <vector>
#include <vec2.hpp>
class ClosedLineSequence
{
private:
	std::vector<glm::vec2> points;
	glm::vec2 lastPoint = glm::vec2(-1, -1);
	bool closed = false;
public:
	ClosedLineSequence(glm::vec2 begin) {
		AddPoint(begin);
	}
	void AddPoint(glm::vec2 newPoint);
	void EndPolygon();
	const std::vector<glm::vec2> getPoints() { return points; }
	const bool isClosed() { return closed; }
};
