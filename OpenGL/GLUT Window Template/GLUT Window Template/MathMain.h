#pragma once
#include <iostream>
//  Include GLUT, OpenGL, and GLU libraries
#include <gl/glut.h>
#include <vec2.hpp>
#include "Color.h"
#include "Drawing.h"
#include "DropDownMenu.h"
#include "ClosedLineSequence.h"
#include "DrawingMode.h"
class MathMain {
private:
	static MathMain* instance;
	static glm::vec2 screenSize;
	Geometry* geometry;
	Drawing* drawing;
	DrawingMode* mode;
	DropDownMenu* menu;
	
public:
	MathMain() {
		this->geometry= new Geometry();
		this->drawing = new Drawing();
		this->mode = new DrawingMode(geometry,drawing);
		this->menu = new DropDownMenu(mode);
		instance = this;
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
	static void Reshape(int w, int h) {
		screenSize = glm::vec2(w, h);
	}
	static void DisplayWrapper() {
		glClear(GL_COLOR_BUFFER_BIT);
		auto inst = getInstance();
		inst->drawing->DrawAllGeometry(inst->geometry);
		glutSwapBuffers();
	}
};


