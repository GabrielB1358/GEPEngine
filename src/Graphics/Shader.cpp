#include "Shader.h"
#include <vector>
#include <iostream>
#include "Texture.h"
#include "WavefrontMesh.h"
#include "Vao.h"

Shader::Shader(std::string _fragPath, std::string _vertPath) : programId(glCreateProgram())
{
	fragmentShader = CreateShader(_fragPath, GL_FRAGMENT_SHADER);
	vertexShader = CreateShader(_vertPath, GL_VERTEX_SHADER);
	Link();
}

Shader::~Shader()
{
	glDetachShader(fragmentShader, programId);
	glDetachShader(vertexShader, programId);
	glDeleteShader(fragmentShader);
	glDeleteShader(vertexShader);
}

GLuint Shader::CreateShader(std::string _shaderPath, GLuint _type)
{
	//Creates shader and attaches to program or throws an accurate error on why it couldn't
	fileString = ReadFile(_shaderPath);
	const GLchar* shader = fileString.c_str();

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
	glAttachShader(programId, temp);
	return temp;
}


void Shader::Render(std::shared_ptr<WavefrontMesh> _mesh, std::shared_ptr<Texture> _texture, Camera* _camera, glm::mat4 _modelMatrix)
{
	//Select program to use
	glUseProgram(programId);

	//Bind Mesh to the vertex array
	glBindVertexArray(_mesh->GetId());

	//Bind texture
	glBindTexture(GL_TEXTURE_2D, _texture->GetId());

	//Bind to this shader
	//BindShader("u_Projection", _camera->GetProjMat());
	//BindShader("u_Model", _modelMatrix);
	//BindShader("u_Viewing", _camera->GetViewMat());

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

void Shader::Render(std::shared_ptr<Vao> _Vao, std::shared_ptr<Texture> _texture)
{
	//Select program to use
	glUseProgram(programId);

	//Bind Mesh to the vertex array
	glBindVertexArray(_Vao->GetId());

	//Bind texture
	glBindTexture(GL_TEXTURE_2D, _texture->GetId());

	//Bind this shader
	//BindShader("u_Projection", _camera->GetProjMat());
	//BindShader("u_Model",_modelMatrix);

	//draw the 3 triangle vertices
	glDrawArrays(GL_TRIANGLES, 0, 6);

	//reset the state
	glBindVertexArray(0);
	glUseProgram(0);
	glBindTexture(GL_TEXTURE_2D,0);

}


GLuint Shader::GetProgramId()
{
	return programId;
}

//Link the program
void Shader::Link()
{
	glBindAttribLocation(programId, 0, "a_Position");
	glBindAttribLocation(programId, 1, "a_TexCoord");
	GLint success = 1;
	glLinkProgram(programId);
	glGetProgramiv(programId, GL_LINK_STATUS, &success);
}


//dynamic shader + matrix binding
void Shader::BindShader(const char* _name, glm::mat4 _matrix)
{
	glProgramUniformMatrix4fv(programId, glGetUniformLocation(programId, _name), 1, GL_FALSE, glm::value_ptr(_matrix));
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


