#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>
#include <iostream>



struct Texture
{
	Texture(const std::string& _path);
	Texture(GLuint _texId);
	Texture();
	~Texture();

	void UploadToGPU();
	GLuint GetId();

private:
	std::vector<float> m_pixels;
	glm::ivec2 m_size;
	GLuint m_Id;
	bool m_dirty;
	unsigned char* m_data;

};