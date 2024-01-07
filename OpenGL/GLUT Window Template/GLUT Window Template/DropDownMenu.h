#pragma once
#include <gl/glut.h>
#include "DrawingMode.h"
class DropDownMenu
{
private:
	DrawingMode* mode;
public:
	DropDownMenu(DrawingMode* mode);
	void Menu(int x, int y);
	static void HandleMenu(int value);
	static void HandleColor(int value);
	static void HandleBrush(int value);
	static void HandleMode(int value);
};

