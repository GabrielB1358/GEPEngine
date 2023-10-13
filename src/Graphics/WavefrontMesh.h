#include <GL/glew.h>
#include <glm/glm.hpp>
#include <bugl.h>
#include <vector>
#include <iostream>

struct WavefrontMesh
{
	WavefrontMesh(const std::string _path, size_t _vertices);
	GLuint GetId();
	size_t GetVertCount();

private:
	GLuint m_Id;
	std::string m_path;
	size_t vertCount;
	bool m_dirty;
};