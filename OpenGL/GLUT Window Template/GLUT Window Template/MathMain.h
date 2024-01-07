#pragma once
#include <iostream>
//  Include GLUT, OpenGL, and GLU libraries
#include <gl/glut.h>
#include <vec2.hpp>
#include "Color.h"
#include "Drawing.h"
#include "DropDownMenu.h"
#include "ClosedLineSequence.h"
class MathMain {
private:
	static MathMain* instance;
	static glm::vec2 screenSize;
	int brushSize;
	Color color;
	Geometry* geometry;
	Drawing* drawing;
	DropDownMenu* menu;
	ClosedLineSequence* currentPoly=nullptr;
	glm::vec2 lastPos = glm::vec2(-1, -1);
public:
	MathMain(Color color = Color(), int brushSize = 100): color(color),brushSize(brushSize) {
		this->geometry= new Geometry();
		this->drawing = new Drawing();
		this->menu = new DropDownMenu();
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


