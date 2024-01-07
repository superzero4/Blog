#pragma once
#include <vec2.hpp>
#include "Color.h"
#include "Geometry.h"
#include "Drawing.h"
class DrawingMode
{
private:
	int brushSize;
	Color color;
	Geometry* geometry;
	Drawing* drawing;
	ClosedLineSequence* currentPoly = nullptr;
	glm::vec2 lastPos = glm::vec2(-1, -1);
public:
	DrawingMode(Geometry* geometry, Drawing* drawing, Color color = Color(), int brushSize = 100) : color(color), brushSize(brushSize), geometry(geometry), drawing(drawing) {}
	void LeftButtonDown(glm::vec2 pos);
	void RightButtonDown(glm::vec2 pos);
};

