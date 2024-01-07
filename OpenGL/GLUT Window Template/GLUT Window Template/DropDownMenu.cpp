#include "DropDownMenu.h"

void DropDownMenu::Menu(int x, int y)
{

}

void DropDownMenu::HandleMenu(int value)
{
}

void DropDownMenu::HandleColor(int value)
{
}

void DropDownMenu::HandleBrush(int value)
{
}

void DropDownMenu::HandleMode(int value)
{
}

DropDownMenu::DropDownMenu(DrawingMode* mode) :mode(mode)
{
	int color, width, modeIndex;
	modeIndex = glutCreateMenu(HandleMode);
		glutAddMenuEntry("Polygon", 0);
		glutAddMenuEntry("Clipping window", 1);
	color = glutCreateMenu(HandleColor);
		glutAddMenuEntry("Red", 1);
		glutAddMenuEntry("Green", 2);
		glutAddMenuEntry("Blue", 2);
	width= glutCreateMenu(HandleBrush);
		glutAddMenuEntry("5", 0);
		glutAddMenuEntry("50", 1);
		glutAddMenuEntry("250", 2);
	int main = glutCreateMenu(HandleMenu);
		glutAddSubMenu("Mode", modeIndex);
		glutAddSubMenu("Color",color);
		//glutAddSubMenu("Width", width);
	glutSetMenu(main);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

