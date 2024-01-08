#pragma once
#include <gl/glut.h>
#include "DrawingMode.h"
class DropDownMenu
{
private:
	DrawingMode* mode;
public:
	DropDownMenu(DrawingMode* mode);
	void HandleMenu(int value);
	void HandleColor(int value);
	void HandleBrush(int value);
	void HandleMode(int value);
};

