#include "DropDownMenu.h"

DropDownMenu::DropDownMenu(DrawingMode* mode) :mode(mode)
{

}

void DropDownMenu::HandleMenu(int value)
{
}

void DropDownMenu::HandleColor(int value)
{
	switch (value) {
	case 0: mode->color = Color(1.0f, 0.0f, 0.0f);
		break; 
	case 1: mode->color = Color(0.0f, 1.0f, 0.0f);
		break;
	case 2: mode->color = Color(0.0f, 0.0f, 1.0f);
		break;
	}
}

void DropDownMenu::HandleBrush(int value)
{
}

void DropDownMenu::HandleMode(int value)
{
	switch (value) {
	case 0:case 1: mode->simpleLine = false;
		mode->polygonColor = value == 0 ? Color(1.0f, 1.0f, 0.0f) : Color(0.0f, 1.0f, 1.0f);
		break;
	case 2: mode->simpleLine = true;
	}
}

