#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>
#include <iostream>


namespace Graphics
{
	struct Texture
	{
		Texture(const std::string& _path);
		Texture(GLuint _texId);
		Texture();
		~Texture();

		void UploadToGPU();
		GLuint GetId();

	private:
		std::shared_ptr<Texture> m_texture;
		std::vector<float> m_pixels;
		glm::ivec2 m_size;
		GLuint m_Id;
		bool m_dirty;
		unsigned char* m_data;

	};
}