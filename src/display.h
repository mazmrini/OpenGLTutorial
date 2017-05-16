/*
 * display.h
 *
 *  Created on: May 14, 2017
 *      Author: lucky
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <string>
#include <SDL2/SDL.h>

class Display {

public:
	Display(int width, int height, const std::string& title);
	virtual ~Display();

	void changeBackgroundColor(float r, float g, float b, float a);
	void clear();
	void update();
	bool isClosed();

private:
	SDL_Window* m_window;
	SDL_GLContext m_glContext; // to use openGL

	bool m_isClosed;
	float m_red;
	float m_blue;
	float m_green;
	float m_alpha;
};

#endif /* DISPLAY_H_ */
