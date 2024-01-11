#include <GL/glew.h>
#include <glm/glm.hpp>
#include <exception>

namespace Graphics
{
	struct RenderTexture
	{
		RenderTexture(int _width, int _height);
		~RenderTexture();

		void Bind();
		void Unbind();

		GLuint GetTexture();

	private:
		GLuint m_fboId;
		GLuint m_texId;
		GLuint m_rboId;
		int m_width;
		int m_height;
		bool m_dirty;

	};
}