#include "DrawingMode.h"
#include <iostream>
#include <GL/glut.h>
#include "ClosedLineSequence.h"
#include "Line.h"

void DrawingMode::LeftButtonDown(glm::vec2 pos)
{
	if (simpleLine) {
		//We are not drawing a polygon so we just draw freeLine
		if (lastPos.x != -1 && lastPos.y != -1) {
			std::cout << "2nd MouseClick " << pos.x << "," << pos.y << std::endl;
			//MousePosition is starting from top left but pixel coordinance from bottom left
			drawing->AddGeometry(new Line(lastPos, pos, color));
			lastPos = glm::vec2(-1, -1);
		}
		else {
			lastPos = pos;
			std::cout << "1st MouseClick " << lastPos.x << "," << lastPos.y << std::endl;
		}
	}
	else {
		//We are drawing a polygon
		if (currentPoly == nullptr) {
			currentPoly = new ClosedLineSequence(pos, polygonColor);
			drawing->AddGeometry(currentPoly);
			glutDetachMenu(GLUT_RIGHT_BUTTON);
		}
		else {
			currentPoly->AddPoint(pos);
		}
	}
}

void DrawingMode::RightButtonDown(glm::vec2 pos)
{
	std::cout << "Right Mouse " << (currentPoly == nullptr) << " <= currentPoly" << std::endl;
	if (currentPoly != nullptr) {
		currentPoly->EndPolygon();
		currentPoly = nullptr;
		glutAttachMenu(GLUT_RIGHT_BUTTON);
	}
}
