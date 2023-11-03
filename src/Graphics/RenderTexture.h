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
		int width;
		int height;
		int w{ 0 };
		int h{ 0 };
		bool dirty;

	};
}