/*
 * texture.h
 *
 *  Created on: May 20, 2017
 *      Author: lucky
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <string>
#include <GL/glew.h>

class Texture {
public:
	Texture(const std::string& fileName);
	virtual ~Texture();

	void bind(unsigned int unit);
private:
	// given binding reference
	GLuint m_texture;
};

#endif /* TEXTURE_H_ */
