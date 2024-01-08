#pragma once
#include <vec2.hpp>
#include "Color.h"
#include "Drawing.h"
#include "ClosedLineSequence.h"
class DrawingMode
{
private:
	int brushSize;
	Drawing* drawing;
	ClosedLineSequence* currentPoly = nullptr;
	glm::vec2 lastPos = glm::vec2(-1, -1);
public:
	bool simpleLine;
	Color color;
	Color polygonColor;
	DrawingMode( Drawing* drawing, Color color = Color(), int brushSize = 100) : color(color), brushSize(brushSize), drawing(drawing) {}
	void LeftButtonDown(glm::vec2 pos);
	void RightButtonDown(glm::vec2 pos);
};

