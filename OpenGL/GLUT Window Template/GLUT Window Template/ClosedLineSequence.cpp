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

void ClosedLineSequence::Draw() const
{
	for (size_t i = 0; i < points.size() - 1; i++)
		DrawLine(points[i], points[i + 1],color);
	if (closed)
		DrawLine(points[points.size() - 1], points[0],color);
}
