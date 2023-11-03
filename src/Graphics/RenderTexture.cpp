#include "RenderTexture.h"



// NEED TO CHANGE RENDER TEXTURE SO THAT IT ACTUALLY IS RENDERTEXTURE AND NOT REGULAR TEXTURE CLASS

namespace Graphics
{
	RenderTexture::RenderTexture(int _width, int _height) : m_fboId(0), m_texId(0), m_rboId(0)
	{
		width = _width;
		height = _height;

		dirty = true;
	}

	RenderTexture::~RenderTexture()
	{
		glDeleteFramebuffers(1, &m_fboId);
		glDeleteTextures(1, &m_texId);
		glDeleteRenderbuffers(1, &m_rboId);
	}

	void RenderTexture::Bind()
	{
		//if the dirty flag is true it binds the render texture so that it can be drawn on to
		if (dirty)
		{
			//set up frame buffer, texture and render buffer
			dirty = false;
			glGenFramebuffers(1, &m_fboId);
			if (!m_fboId) { throw std::exception(); }
			glBindFramebuffer(GL_FRAMEBUFFER, m_fboId);

			glGenTextures(1, &m_texId);
			glBindTexture(GL_TEXTURE_2D, m_texId);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
				GL_UNSIGNED_BYTE, NULL);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glBindTexture(GL_TEXTURE_2D, 0);
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_texId, 0);

			glGenRenderbuffers(1, &m_rboId);
			glBindRenderbuffer(GL_RENDERBUFFER, m_rboId);
			glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
			glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, m_rboId);
			glBindRenderbuffer(GL_RENDERBUFFER, 0);
		}
		glBindFramebuffer(GL_FRAMEBUFFER, m_fboId);
	}

	void RenderTexture::Unbind()
	{
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	GLuint RenderTexture::GetTexture()
	{
		//returns texture ID
		glBindTexture(GL_TEXTURE_2D, m_texId);
		glGenerateMipmap(GL_TEXTURE_2D);
		return m_texId;
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}
