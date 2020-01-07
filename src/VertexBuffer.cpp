#include "VertexBuffer.h"
#include <GL/glew.h>

VertexBuffer::VertexBuffer(const float* verticies, int verticiesCount, const int attributes[], int attributesCount) {
	init(attributes, attributesCount);

	bind();
	glBufferData(GL_ARRAY_BUFFER, verticiesCount * m_attributesStride * sizeof(float), verticies, GL_STATIC_DRAW);
	unbind();
}

VertexBuffer::VertexBuffer(const int attributes[], int attributesCount) {
	init(attributes, attributesCount);
}

VertexBuffer::~VertexBuffer() {
	glDeleteBuffers(1, &m_vertexBufferId);
}

void VertexBuffer::bind() {
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferId);
}

void VertexBuffer::unbind() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::setData(const float* verticies, int verticiesCount) {
	bind();
	glBufferData(GL_ARRAY_BUFFER, verticiesCount * m_attributesStride * sizeof(float), verticies, GL_DYNAMIC_DRAW);
}

void VertexBuffer::init(const int attributes[], int attributesCount) {
	m_attributesStride = 0;
	for(int i = 0; i < attributesCount; ++i) {
		m_attributesStride += attributes[i];
	}

	glGenBuffers(1, &m_vertexBufferId);
	bind();

	int total = 0;
	for(int i = 0; i < attributesCount; ++i) {
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(i, attributes[i], GL_FLOAT, GL_FALSE, m_attributesStride * sizeof(float), (void*)total);

		total += attributes[i] * sizeof(float);
	}

	unbind();
}