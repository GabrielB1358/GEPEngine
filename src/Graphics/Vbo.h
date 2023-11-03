#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>

namespace Graphics
{
	struct Vbo
	{
		Vbo();
		~Vbo();

		void Add(const glm::vec3& _value);
		void Add(const glm::vec2& _value);
		GLuint GetId();
		int GetComponents() const;

	private:
		GLuint m_Id;
		std::vector<float> m_data;
		bool m_dirty;
		int m_components;
	};
}