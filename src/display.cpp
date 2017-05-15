/*
 * display.cpp
 *
 *  Created on: May 14, 2017
 *      Author: lucky
 */

#include "display.h"
#include <GL/glew.h>
#include <iostream>

Display::Display(int width, int height, const std::string& title) {

	SDL_Init(SDL_INIT_EVERYTHING);

	// 2^8 = 256 colors
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);

	// buffer for colors is at least 32 bits
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);

	// Allocates space for a second "window" for better rendering
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	// SDL is a C library, it needs a C string
	// last parameter is a flag
	m_window = SDL_CreateWindow(title.c_str(),
								SDL_WINDOWPOS_CENTERED,
								SDL_WINDOWPOS_CENTERED,
								width, height,
								SDL_WINDOW_OPENGL);

	// this allows the workflow to be openGL -> GPU -> window
	// without having to go through the OS
	m_glContext = SDL_GL_CreateContext(m_window);

	// finds every openGL function the current OS supports
	GLenum status = glewInit();

	if (status != GLEW_OK)
		std::cerr << "Glew failed to initialize." << std::endl;

	m_isClosed = false;
	changeBackgroundColor(0.0f, 0.0f, 0.0f, 0.0f);
}

Display::~Display() {
	// delete the context before the the window
	// because we need the window to create the context
	SDL_GL_DeleteContext(m_glContext);
	SDL_DestroyWindow(m_window);
	SDL_Quit();

	std::cout << "Window's closed" << std::endl;
}

void Display::update() {

	glClear(GL_COLOR_BUFFER_BIT);
	// allows the double buffer to do its job
	// this allows to never show an image that still is in the drawing process
	SDL_GL_SwapWindow(m_window);

	SDL_Event e;

	// TODO What is this for ?
	while (SDL_PollEvent(&e))
		if (e.type == SDL_QUIT)
			m_isClosed = true;
}

void Display::changeBackgroundColor(float red, float green, float blue,
									float alpha) {
	glClearColor(red, green, blue, alpha);
}

bool Display::isClosed() {
	return m_isClosed;
}
