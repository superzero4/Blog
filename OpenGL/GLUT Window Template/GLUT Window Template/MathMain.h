#pragma once
#include <iostream>
//  Include GLUT, OpenGL, and GLU libraries
#include <gl/glut.h>
#include <vec2.hpp>
#include "Color.h"
#include "Drawing.h"
#include "DropDownMenu.h"
class MathMain {
private:
	static MathMain* instance;
	int brushSize;
	Color color;
	Drawing* drawing;
	DropDownMenu* menu;
	glm::vec2 lastPos = glm::vec2(-1, -1);

public:
	MathMain(Color color = Color(), int brushSize = 100) {
		this->brushSize = brushSize;
		this->drawing = new Drawing();
		this->menu = new DropDownMenu();
		this->color = color;
	};
	static MathMain* getInstance() {
		if (instance == nullptr)
			instance = new MathMain();
		return instance;
	}
	void MouseClick(int button, int state, int x, int y);
	static void MouseClickWrapper(int button, int state, int x, int y) {
		getInstance()->MouseClick(button, state, x, y);
	}
	static void MouseDragWrapper(int x, int y) { getInstance()->MouseDrag(x, y); }
	void MouseDrag(int x, int y);
};


