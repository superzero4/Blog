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
#include "SutherHodgClipping.h"
class MathMain {
private:
	static MathMain* instance;
	static glm::vec2 screenSize;
	Drawing* drawing;
	DrawingMode* mode;
	DropDownMenu* menu;
	DropDownMenu* clip;

public:
	MathMain();
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
		inst->drawing->DrawAllGeometry();
		glutSwapBuffers();
	}
#pragma region menuStaticBinding


	static void HandleMenu(int value) {
		getInstance()->menu->HandleMenu(value);
	}
	static void HandleMode(int value) {
		getInstance()->menu->HandleMode(value);
	}
	static void HandleColor(int value) {
		getInstance()->menu->HandleColor(value);
	}
	static void HandleBrush(int value) {
		getInstance()->menu->HandleBrush(value);
	}
	static void HandleClip(int value) {
		getInstance()->menu->HandleClip(value);
	}
#pragma endregion
};


