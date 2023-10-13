#include "WavefrontMesh.h"

WavefrontMesh::WavefrontMesh(const std::string _path, size_t _vertices)
{
	m_path = _path;
	vertCount = _vertices;
	m_Id = buLoadModel(_path.c_str(), vertCount);
}

GLuint WavefrontMesh::GetId()
{
	return m_Id;
}

size_t WavefrontMesh::GetVertCount()
{
	return vertCount;
}