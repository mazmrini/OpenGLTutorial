//============================================================================
// Name        : OpenGLTutorial.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "display.h"
#include <GL/glew.h>

using namespace std;

int main() {
	Display display(800, 600, "Hello World!");
	display.changeBackgroundColor(0.0f, 0.15f, 0.3f, 1.0f);

	while (!display.isClosed()) {
		display.update();
	}

	return 0;
}
