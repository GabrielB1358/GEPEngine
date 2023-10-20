#include "Camera.h"

Camera::Camera(bool _isOrtho)
{
	_cameraPos = glm::vec3(0.0f, 8.0f, 17.0f);
	glm::vec3 initTarget = glm::vec3(-100.0f, 0.0f, 0.0f);

	_cameraAngleX = -0.4f;
	_cameraAngleY = 0.005f;

	speed = 0.1f;
	mouseSpeed = 0.005f;

	//Different projection matrix logic for if the camera is orthographic or otherwise
	if (_isOrtho)
	{
		_projMatrix = glm::ortho(0.0f, 1920.0f, 0.0f, 1080.0f, 0.0f, 1.0f);
	}
	else
	{ 
		_projMatrix = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
	}


	_viewMatrix = glm::lookAt(_cameraPos, initTarget, _up);
}

Camera::~Camera() {}

/*void Camera::Update(UserInput* _input)
{
	//cameras rotation is updated using the mouse movement from the input class
	//cameras position is updated using the WASD keys

	_cameraAngleY -= _input->mouseMove.x * mouseSpeed;
	_cameraAngleX -= _input->mouseMove.y * mouseSpeed;

	glm::mat4 direction(1.0f);
	direction = glm::rotate(direction, _cameraAngleY, glm::vec3(0, 1, 0));
	direction = glm::rotate(direction, _cameraAngleX, glm::vec3(1, 0, 0));

	//Moving camera with WASD keys
	if (_input->key_S)
	{
		_translation = (direction * glm::vec4(0, 0, 1, 1)) * speed;
		_cameraPos += _translation;
	}
	else if (_input->key_W)
	{
		_translation = (direction * glm::vec4(0, 0, -1, 1)) * speed;
		_cameraPos += _translation;
	}

	if (_input->key_D)
	{
		_translation = (direction * glm::vec4(1, 0, 0, 1)) * speed;
		_cameraPos += _translation;
	}
	else if (_input->key_A)
	{
		_translation = (direction * glm::vec4(-1, 0, 0, 1)) * speed;
		_cameraPos += _translation;
	}

	//view matrix is reset then rotation and positon are applied and it is inversed as to display
	//things the right way around
	_viewMatrix = glm::mat4(1.0f);
	_viewMatrix = glm::translate(_viewMatrix, _cameraPos);
	_viewMatrix = glm::rotate(_viewMatrix, _cameraAngleY, glm::vec3(0, 1, 0));
	_viewMatrix = glm::rotate(_viewMatrix, _cameraAngleX, glm::vec3(1, 0, 0));
	_viewMatrix = glm::inverse(_viewMatrix);
}*/