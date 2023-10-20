#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
//#include "UserInput.h"

struct Camera
{
public:
	Camera(bool _isOrtho);
	~Camera();

	//using Inline functions as they can increase efficiency in small doses
	inline glm::mat4 GetViewMat() { return _viewMatrix; }

	inline glm::mat4 GetProjMat() { return _projMatrix; }

	void SetViewMat(glm::mat4 _view) { _viewMatrix = _view; }

	void SetProjMat(glm::mat4 _proj) { _projMatrix = _proj; }

	inline void SetPos(glm::vec3 pos) { _cameraPos = pos; }

	//void Update(UserInput* _input);


private:

	glm::mat4 _viewMatrix;

	glm::mat4 _projMatrix;

	glm::vec3 _cameraPos;

	glm::vec3 cameraRot;

	glm::vec3 _lookAt;

	glm::vec3 _up;

	glm::vec3 _translation;

	float _cameraAngleX;

	float _cameraAngleY;

	float speed;
	
	float mouseSpeed;

	int posX, posY;
};