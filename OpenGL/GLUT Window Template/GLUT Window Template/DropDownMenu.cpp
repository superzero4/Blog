#include "DropDownMenu.h"

void DropDownMenu::Menu(int x, int y)
{

}

void DropDownMenu::HandleMenu(int value)
{
}

DropDownMenu::DropDownMenu()
{
	return;
	throw "Unimplemented, causes stack overflow";
	int main = glutCreateMenu(HandleMenu);
	glutAddSubMenu("Color",main);
	glutAddMenuEntry("Red", 0);
	glutAddMenuEntry("Green", 1);
	glutAddMenuEntry("Blue", 2);
	glutAddSubMenu("Width", main);
	glutAddMenuEntry("5", 0);
	glutAddMenuEntry("50", 1);
	glutAddMenuEntry("250", 2);
	glutSetMenu(main);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

