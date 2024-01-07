#include "DrawingMode.h"
#include <iostream>
#include "ClosedLineSequence.h"

void DrawingMode::LeftButtonDown(glm::vec2 pos)
{
	if (currentPoly == nullptr) {
		//We are not drawing a polygon so we just draw freeLine
		if (lastPos.x != -1 && lastPos.y != -1) {
			//std::cout << "2nd MouseClick " << lastPos.x << "," << lastPos.y << std::endl;
			//MousePosition is starting from top left but pixel coordinance from bottom left
			geometry->AddLine(lastPos, pos);
			lastPos = glm::vec2(-1, -1);
		}
		else {
			lastPos = pos;
			std::cout << "1st MouseClick " << lastPos.x << "," << lastPos.y << std::endl;
		}
	}
	else {
		//We are drawing a polygon
		currentPoly->AddPoint(pos);
	}
}

void DrawingMode::RightButtonDown(glm::vec2 pos)
{
	std::cout << "Right Mouse " << (currentPoly == nullptr) << " <= currentPoly" << std::endl;
	if (currentPoly == nullptr) {
		currentPoly = new ClosedLineSequence(pos);
		geometry->AddPoly(currentPoly);
	}
	else {
		currentPoly->EndPolygon();
		currentPoly = nullptr;
	}
}
