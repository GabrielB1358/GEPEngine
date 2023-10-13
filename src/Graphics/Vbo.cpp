#include "Vbo.h"

#include <stdexcept>

Vbo::Vbo() : m_Id(0), m_dirty(false), m_components(0) {}
Vbo::~Vbo() {}

void Vbo::Add(const glm::vec3& _value)
{
	m_data.push_back(_value.x);
	m_data.push_back(_value.y);
	m_data.push_back(_value.z);
	m_dirty = true;
	m_components = 3;
}

void Vbo::Add(const glm::vec2& _value)
{
	m_data.push_back(_value.x);
	m_data.push_back(_value.y);
	m_dirty = true;
	m_components = 2;
}

int Vbo::GetComponents() const
{
	if (!m_components) { throw std::runtime_error("Not yet set"); }
	return m_components;
}

GLuint Vbo::GetId()
{
	if (!m_Id)
	{
		glGenBuffers(1, &m_Id);
		if (!m_Id) { throw std::runtime_error("Failed to allocated VBO"); }
	}
	if (m_dirty)
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_Id);

		//upload a copy of the data from memory into the vertex buffer object
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * m_data.size(),&m_data.at(0), GL_STATIC_DRAW);

		//reset the state (unbind it)
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		m_dirty = false;
	}
	return m_Id;
}

