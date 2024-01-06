#pragma once

#include <glm/gtc/type_ptr.hpp>
#include <string>
#include <GL/glew.h>
#include <memory>
#include <GEPEngine/Camera.h>

namespace Graphics
{
	struct Vao;
	struct Camera;
	struct Texture;
	struct WavefrontMesh;
	struct Shader
	{
		Shader(std::string _fragPath, std::string _vertPath);
		~Shader();

		GLuint CreateShader(const std::string _shaderPath, GLuint _type);
		GLuint GetProgramId();
		void Link();
		void BindShader(const char* _name, glm::mat4 _matrix);

		void Render(std::shared_ptr<WavefrontMesh> _mesh, std::shared_ptr<Texture> _texture, std::shared_ptr<GEPEngine::Camera> _camera, glm::mat4 _modelMatrix);
		void Render(std::shared_ptr<Vao> _vao, std::shared_ptr<Texture> _texture, glm::mat4 _modelMatrix, std::shared_ptr<GEPEngine::Camera> _camera);

		std::string ReadFile(std::string _path);

	private:
		std::shared_ptr<Shader> m_shader;
		std::string fileString;
		GLuint fragmentShader;
		GLuint vertexShader;
		GLuint programId;
		const GLchar* src;
	};
}