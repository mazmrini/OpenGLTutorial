/*
 * shader.h
 *
 *  Created on: May 15, 2017
 *      Author: lucky
 */

#ifndef SHADER_H_
#define SHADER_H_

#include <string>
#include <GL/glew.h>

class Shader {
public:
	Shader(const std::string& fileName);
	virtual ~Shader();
	void bind();
private:
	static const unsigned int NUM_SHADERS = 2;
	GLuint m_program; // where the program is
	GLuint m_shaders[NUM_SHADERS];
};

#endif /* SHADER_H_ */
