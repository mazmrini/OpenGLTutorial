//============================================================================
// Name        : OpenGLTutorial.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "display.h"
#include "shader.h"
#include "mesh.h"

using namespace std;

int main() {
	Display display(800, 600, "Hello World!");
	display.changeBackgroundColor(0.0f, 0.15f, 0.3f, 1.0f);

	// extensions are added in constructor
	Shader shader("./res/basicShader");

	// coordinates are as in a normal graph in (x, y, z) format
	Vertex vertices[] = { Vertex(glm::vec3(-0.25, -0.25, 0)),
						  Vertex(glm::vec3(0, 0.25, 0)),
						  Vertex(glm::vec3(0.25, -0.25, 0))
						};

	unsigned int nbVertices = sizeof(vertices) / sizeof(vertices[0]);
	Mesh mesh(vertices, nbVertices);

	while (!display.isClosed()) {
		display.clear();

		shader.bind();
		mesh.draw();

		display.update();
	}

	return 0;
}
