#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>
#include <string>
#include <memory>


namespace Graphics
{
	struct Vbo;
	struct Vao
	{
		Vao();
		~Vao();

		GLuint GetId();
		void AddVbo(std::shared_ptr<Vbo> _targetVbo);

	private:
		GLuint m_Id;
		bool m_dirty;
		std::vector<std::shared_ptr<Vbo>> m_Vbos{};
	};
}