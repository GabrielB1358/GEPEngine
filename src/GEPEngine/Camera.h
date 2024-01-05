#pragma once
#include <GEPEngine/MyEngine.h>


namespace GEPEngine
{

	//maybe make camera inherit from entity?
	struct Camera // : Entity? : Component?
	{

	public:
		//COPYING MY 3DGP STUFF RN
		inline glm::mat4 getViewMat() { return m_viewMatrix; }

		inline glm::mat4 getProjMat() { return m_projectionMatrix; }

		void setViewMat(glm::mat4 _view) { m_viewMatrix = _view; }

		void setProjMat(glm::mat4 _proj) { m_projectionMatrix = _proj; }

		inline void setPos(glm::vec3 _pos) { m_cameraPos = _pos; }

	private:

		glm::mat4 m_viewMatrix;
		
		glm::mat4 m_projectionMatrix;

		glm::vec3 m_cameraPos;

		glm::vec3 m_cameraRot;

		glm::vec3 m_lookAt;

		glm::vec3 m_up;

		glm::vec3 m_translation;

		float m_cameraAngleX;

		float m_cameraAngleY;

		float m_speed;

		float m_mouseSpeed;

		int posX, posY;


	};
}