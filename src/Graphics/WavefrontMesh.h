#include <GL/glew.h>
#include <glm/glm.hpp>
#include <bugl.h>
#include <vector>
#include <iostream>

namespace Graphics
{
	struct WavefrontMesh
	{
		WavefrontMesh(const std::string _path);
		GLuint GetId();
		size_t GetVertCount();

	private:
		GLuint m_Id;
		std::string m_path;
		size_t m_vertCount;
		bool m_dirty;
	};
}
