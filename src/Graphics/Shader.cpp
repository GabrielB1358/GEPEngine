#include "Shader.h"
#include <vector>
#include <iostream>
#include "Texture.h"
#include "WavefrontMesh.h"
#include "Vao.h"


namespace Graphics
{
	Shader::Shader(std::string _fragPath, std::string _vertPath) : m_programId(glCreateProgram())
	{
		m_fragmentShader = CreateShader(_fragPath, GL_FRAGMENT_SHADER);
		m_vertexShader = CreateShader(_vertPath, GL_VERTEX_SHADER);
		Link();
	}

	Shader::~Shader()
	{
		glDetachShader(m_fragmentShader, m_programId);
		glDetachShader(m_vertexShader, m_programId);
		glDeleteShader(m_fragmentShader);
		glDeleteShader(m_vertexShader);
	}


	GLuint Shader::CreateShader(std::string _shaderPath, GLuint _type)
	{
		//Creates shader and attaches to program or throws an accurate error on why it couldn't
		m_fileString = ReadFile(_shaderPath);
		const GLchar* shader = m_fileString.c_str();

		GLint success = 0;
		GLuint temp = glCreateShader(_type);
		glShaderSource(temp, 1, &shader, NULL);
		glCompileShader(temp);
		glGetShaderiv(temp, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			GLint maxLength = 0;
			glGetShaderiv(temp, GL_INFO_LOG_LENGTH, &maxLength);
			std::vector<GLchar> errorLog(maxLength);
			glGetShaderInfoLog(temp, maxLength, &maxLength, &errorLog[0]);
			std::cout << &errorLog.at(0) << std::endl;
			throw std::exception();
		}
		glAttachShader(m_programId, temp);
		return temp;
	}

	//Render function for 3D models
	void Shader::Render(std::shared_ptr<WavefrontMesh> _mesh, std::shared_ptr<Texture> _texture, std::shared_ptr<GEPEngine::Camera> _camera, glm::mat4 _modelMatrix, glm::vec3 _lightPos)
	{
		//Select program to use
		glUseProgram(m_programId);

		//Bind Mesh to the vertex array
		glBindVertexArray(_mesh->GetId());

		//Bind texture
		glBindTexture(GL_TEXTURE_2D, _texture->GetId());

		//Bind to this shader
		BindShader("u_Projection", _camera->getPerspProjMat());
		BindShader("u_Model", _modelMatrix);
		BindShader("u_Viewing", _camera->getViewMat());
		glProgramUniform3f(m_programId, glGetUniformLocation(m_programId, "u_LightPos"), _lightPos.x, _lightPos.y, _lightPos.z);

		//Enable anything appropriate
		glEnable(GL_DEPTH_TEST);

		//draw the 3 triangle vertices
		glDrawArrays(GL_TRIANGLES, 0, _mesh->GetVertCount());

		//reset the state
		glBindVertexArray(0);
		glUseProgram(0);
		glDisable(GL_DEPTH_TEST);

		glBindTexture(GL_TEXTURE_2D, 0);

	}

	void Shader::RenderPerspQuad(std::shared_ptr<Vao> _vao, std::shared_ptr<Texture> _texture, std::shared_ptr<GEPEngine::Camera> _camera, glm::mat4 _modelMatrix, glm::vec3 _lightPos)
	{
		//Select program to use
		glUseProgram(m_programId);

		//Bind Mesh to the vertex array
		glBindVertexArray(_vao->GetId());

		//Bind texture
		glBindTexture(GL_TEXTURE_2D, _texture->GetId());

		//Bind to this shader
		BindShader("u_Projection", _camera->getPerspProjMat());
		BindShader("u_Model", _modelMatrix);
		BindShader("u_Viewing", _camera->getViewMat());
		glProgramUniform3f(m_programId, glGetUniformLocation(m_programId, "u_LightPos"), _lightPos.x, _lightPos.y, _lightPos.z);

		//Enable anything appropriate
		//glEnable(GL_DEPTH_TEST);

		//draw the 3 triangle vertices
		glDrawArrays(GL_TRIANGLES, 0, 6);

		//reset the state
		glBindVertexArray(0);
		glUseProgram(0);
		//glDisable(GL_DEPTH_TEST);

		glBindTexture(GL_TEXTURE_2D, 0);

	}

	//Render function for 2D, orthographic things
	void Shader::RenderQuad(std::shared_ptr<Vao> _Vao, std::shared_ptr<Texture> _texture, glm::mat4 _modelMatrix, std::shared_ptr<GEPEngine::Camera> _camera)
	{

		//Select program to use
		glUseProgram(m_programId);

		//Bind Mesh to the vertex array
		glBindVertexArray(_Vao->GetId());

		//Bind texture
		glBindTexture(GL_TEXTURE_2D, _texture->GetId());

		//Bind this shader
		BindShader("u_Projection", _camera->getOrthoProjMat());
		BindShader("u_Model", _modelMatrix);

		//draw the 3 triangle vertices
		glDrawArrays(GL_TRIANGLES, 0, 6);

		//reset the state
		glBindVertexArray(0);
		glUseProgram(0);
		glBindTexture(GL_TEXTURE_2D, 0);

	}


	GLuint Shader::GetProgramId()
	{
		return m_programId;
	}

	//Link the program
	void Shader::Link()
	{
		glBindAttribLocation(m_programId, 0, "a_Position");
		glBindAttribLocation(m_programId, 1, "a_TexCoord");
		GLint success = 1;
		glLinkProgram(m_programId);
		glGetProgramiv(m_programId, GL_LINK_STATUS, &success);
	}


	//dynamic shader + matrix binding
	void Shader::BindShader(const char* _name, glm::mat4 _matrix)
	{
		glProgramUniformMatrix4fv(m_programId, glGetUniformLocation(m_programId, _name), 1, GL_FALSE, glm::value_ptr(_matrix));
	}

	std::string Shader::ReadFile(std::string _path)
	{
		//opens file from path in function parameter
		//copies entirety of file into a std string and returns it
		std::string line;
		std::string fileString = "";
		std::ifstream file(_path);
		if (file.is_open())
		{
			while (std::getline(file, line)) { fileString += line + '\n'; }
			file.close();
		}
		else { throw std::runtime_error("Can't open shader file"); }

		return fileString;
	}
}


