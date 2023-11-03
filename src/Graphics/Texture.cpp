#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


namespace Graphics
{
	Texture::Texture(const std::string& _path) : m_size{ 0 }
	{
		m_data = stbi_load(_path.c_str(), &m_size.x, &m_size.y, NULL, 4);
		if (!m_data) { throw std::exception(); }
		else { UploadToGPU(); }
	}

	Texture::Texture(GLuint _texID) : m_Id(_texID)
	{
	}

	Texture::Texture()
	{
	}

	Texture::~Texture()
	{
		glDeleteTextures(1, &m_Id);
	}



	void Texture::UploadToGPU()
	{
		//Create texture, bind it and error check
		m_Id = 0;
		glGenTextures(1, &m_Id);
		if (!m_Id) { throw std::exception(); }

		glBindTexture(GL_TEXTURE_2D, m_Id);

		//Upload image data to the bound texture unit in the GPU
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_size.x, m_size.y, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_data);

		//Free the loaded data now that its uploaded to the GPU
		free(m_data);

		//Generate mipmap so the texture can be mapped correctly
		glGenerateMipmap(GL_TEXTURE_2D);

		//Unbind the texture because its finished being operated on
		glBindTexture(GL_TEXTURE_2D, 0);

		//Enable blending
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	}

	GLuint Texture::GetId()
	{
		return m_Id;
	}
}