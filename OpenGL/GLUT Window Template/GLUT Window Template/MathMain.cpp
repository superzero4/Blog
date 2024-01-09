#include "MathMain.h"


MathMain* MathMain::instance = nullptr;
glm::vec2 MathMain::screenSize;
MathMain::MathMain()
{
	this->drawing = new Drawing();
	this->mode = new DrawingMode(drawing);
	this->menu = new DropDownMenu(mode);
	this->clip = new DropDownMenu(mode);
	instance = this;
	int color, width, modeIndex, clipping;
	modeIndex = glutCreateMenu(HandleMode);
	glutAddMenuEntry("Polygon", 0);
	glutAddMenuEntry("Clipping window", 1);
	glutAddMenuEntry("Line", 2);
	color = glutCreateMenu(HandleColor);
	glutAddMenuEntry("Red", 0);
	glutAddMenuEntry("Green", 1);
	glutAddMenuEntry("Blue", 2);
	clipping = glutCreateMenu(HandleClip);
	glutAddMenuEntry("Sutherland-Hodgman", 0);
	glutAddMenuEntry("Cyrus-Beck", 1);
	width = glutCreateMenu(HandleBrush);
	glutAddMenuEntry("5", 0);
	glutAddMenuEntry("50", 1);
	glutAddMenuEntry("250", 2);
	int main = glutCreateMenu(HandleMenu);
	glutAddSubMenu("Mode", modeIndex);
	glutAddSubMenu("Color", color);
	glutAddSubMenu("Clipping method", clipping);
	//glutAddSubMenu("Width", width);
	glutSetMenu(main);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void MathMain::MouseClick(int button, int state, int x, int y)
{
	auto pixelSpacePos = glm::vec2(x, screenSize.y - y);
	//std::cout << "MouseClick " << x << "," << y << std::endl;
	if (state == GLUT_DOWN) {
		if (button == GLUT_LEFT_BUTTON) {
			mode->LeftButtonDown(pixelSpacePos);
		}
		else if (button == GLUT_RIGHT_BUTTON) {
			mode->RightButtonDown(pixelSpacePos);
		}
	}
}

void MathMain::MouseDrag(int x, int y)
{
}
