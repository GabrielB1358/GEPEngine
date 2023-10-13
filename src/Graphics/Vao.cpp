#include "Vao.h"
#include <stdexcept>

Vao::Vao() : m_Id(0), m_dirty(false) {}
Vao::~Vao() {}

GLuint Vao::GetId()
{
	if (!m_Id)
	{
		glGenVertexArrays(1, &m_Id);
		if (!m_Id){ throw std::runtime_error("Failed to allocate VAO"); }
	}

	if (m_dirty)
	{
		glBindVertexArray(m_Id);

		//bind the position VBO
		for (int i = 0; i < Vbos.size(); i++)
		{
			glBindBuffer(GL_ARRAY_BUFFER, Vbos[i]->GetId());

			glVertexAttribPointer(i, Vbos[i]->GetComponents(), GL_FLOAT, GL_FALSE, 0, (void*)0);

			glEnableVertexAttribArray(i);
		}

		//reset the state
		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		m_dirty = false;
	}

	return m_Id;
}

void Vao::AddVbo(std::shared_ptr<Vbo> targetVbo)
{
	Vbos.push_back(targetVbo);

	m_dirty = true;
}

