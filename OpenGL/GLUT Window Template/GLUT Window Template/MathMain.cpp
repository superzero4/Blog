#include "MathMain.h"


MathMain* MathMain::instance = nullptr;
void MathMain::MouseClick(int button, int state, int x, int y)
{
	//std::cout << "MouseClick " << x << "," << y << std::endl;
	if (state == GLUT_DOWN) {
		if (button == GLUT_LEFT_BUTTON) {
			if (lastPos.x != -1 && lastPos.y != -1) {
				//std::cout << "2nd MouseClick " << lastPos.x << "," << lastPos.y << std::endl;
				drawing->DrawLine(lastPos, glm::vec2(x, y));
				lastPos = glm::vec2(-1, -1);
			}
			else {
				lastPos = glm::vec2(x, y);
				std::cout << "1st MouseClick " << lastPos.x << "," << lastPos.y << std::endl;
			}
		}
		else if (button == GLUT_RIGHT_BUTTON) {
			
		}
	}
}

void MathMain::MouseDrag(int x, int y)
{
	float* pixels = new float[brushSize * brushSize * 3];
	for (size_t i = 0; i < brushSize; i++)
	{
		for (size_t j = 0; j < brushSize; j++)
		{
			for (size_t colo = 0; colo < 3; colo++)
			{
				pixels[i * brushSize + j + colo] = color[colo];
			}
		}
	}
	//std::cout << brushSize << "MouseDrag " << x << "," << y << std::endl;
	glDrawPixels(brushSize, brushSize, GL_RGB, GL_FLOAT, pixels);
}
