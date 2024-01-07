#include "MathMain.h"


MathMain* MathMain::instance = nullptr;
glm::vec2 MathMain::screenSize;
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
