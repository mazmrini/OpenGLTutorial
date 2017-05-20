/*
 * mesh.h
 *
 *  Created on: May 15, 2017
 *      Author: lucky
 */

#ifndef MESH_H_
#define MESH_H_

#include <glm/glm.hpp>
#include <GL/glew.h>

class Vertex {
public:
	Vertex(const glm::vec3& position, const glm::vec2& texCoord);
	glm::vec3 GetPosition();
	glm::vec2 GetTexCoord();
private:
	glm::vec3 m_position;
	glm::vec2 m_texCoord;
};

class Mesh {
public:
	Mesh(Vertex* vertices, unsigned int numVertices);
	virtual ~Mesh();

	void draw();
private:

	enum {
		POSITION_VB,
		TEXCOORD_VB,
		NUM_BUFFERS
	};

	GLuint m_vertexArrayObject; // included in openGL 3.0
	GLuint m_vertexArrayBuffers[NUM_BUFFERS];
	unsigned int m_drawCount;
};

#endif /* MESH_H_ */
