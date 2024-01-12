#pragma once
#include <GEPEngine/Entity.h>


namespace GEPEngine
{
	struct Entity;

	struct Camera : Component
	{
		//Camera component holds the relevent variables like matrices for effective camera based rendering functionality

	public:

		glm::mat4 getViewMat();
		glm::mat4 getOrthoProjMat();
		glm::mat4 getPerspProjMat();
		glm::vec2 getMouse();
		glm::vec3 getOffset();

		void setViewMat(glm::mat4 _view);
		void setOrthoProjMat(glm::mat4 _proj);
		void setPerspProjMat(glm::mat4 _proj);
		void setPos(glm::vec3 _pos);
		void setOffset(glm::vec3 _ofs);

		void onTick() override;
		void initialise();

	private:
		bool m_isOrtho;

		//Matrices
		glm::mat4 m_viewMatrix;
		glm::mat4 m_orthoProjmat;
		glm::mat4 m_perspProjmat;

		//Vectors
		glm::vec3 m_cameraPos;
		glm::vec3 m_cameraRot;
		glm::vec3 m_lookAt;
		glm::vec3 m_up;
		glm::vec3 m_translation;
		glm::vec3 m_offset;

		//floats
		float m_cameraAngleX;
		float m_cameraAngleY;
		float m_speed;
		float m_mouseSpeed;
	};
}