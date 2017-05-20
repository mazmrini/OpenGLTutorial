/*
 * mesh.cpp
 *
 *  Created on: May 15, 2017
 *      Author: lucky
 */

#include "mesh.h"
#include <vector>

Vertex::Vertex(const glm::vec3& position, const glm::vec2& texCoord) {
	m_position = position;
	m_texCoord = texCoord;
}

glm::vec3 Vertex::GetPosition() {
	return m_position;
}

glm::vec2 Vertex::GetTexCoord() {
	return m_texCoord;
}

Mesh::Mesh(Vertex* vertices, unsigned int numVertices) {
	m_drawCount = numVertices;

	// nb of arrayObject, object to put in the vertex array
	glGenVertexArrays(1, &m_vertexArrayObject);
	// bind the vertices
	glBindVertexArray(m_vertexArrayObject);

	std::vector<glm::vec3> positions;
	std::vector<glm::vec2> texCoords;
	positions.reserve(numVertices);
	texCoords.reserve(numVertices);

	for (unsigned int i = 0; i < numVertices; i++) {
		positions.push_back(vertices[i].GetPosition());
		texCoords.push_back(vertices[i].GetTexCoord());
	}

	// generate data in the GPU
	// second arg is already a pointer
	glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
	// interprets the second arg as an array
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);

	// takes data from RAM and put it in the GPU memory (sort of)
	// how to interpret data, size of data, starting point, draw hint
	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(positions[0]), &positions[0], GL_STATIC_DRAW);

	// gpu needs to look at a sequential array of data
	// not sequential : position, color, position, color
	// tells the gpu that the data is already sequential (position, position, position, etc.)
	glEnableVertexAttribArray(0);
	// each attribute has 3 pieces of floating point data (glm::vec3)
	// GL_FALSE = dont normalize the data, how much it needs to skip to be sequential (0), beginning (0)
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[TEXCOORD_VB]);
	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(texCoords[0]), &texCoords[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glBindVertexArray(0);
}

Mesh::~Mesh() {
	glDeleteVertexArrays(1, &m_vertexArrayObject);
}

void Mesh::draw() {
	glBindVertexArray(m_vertexArrayObject);

	// reads the buffer we sent
	// type of drawing, start of buffer to read, end of buffer to read
	glDrawArrays(GL_TRIANGLES, 0, m_drawCount);

	glBindVertexArray(0);
}

