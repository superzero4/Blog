#include <iostream>
#include "ClosedLineSequence.h"

void ClosedLineSequence::AddPoint(glm::vec2 newPoint)
{
	if (closed) {
		throw "ClosedLineSequence closed";
		return;
	}
	std::cout << "Adding(" << newPoint.x << "," << newPoint.y << ")" << std::endl;
	points.push_back(newPoint);
	lastPoint = newPoint;
}

void ClosedLineSequence::EndPolygon()
{
	AddPoint(points[0]);
	closed = true;
}
