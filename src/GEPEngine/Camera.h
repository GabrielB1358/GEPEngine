#pragma once
#include <GEPEngine/Entity.h>


namespace GEPEngine
{
	struct Entity;

	struct Camera : Component
	{

	public:

		inline glm::mat4 getViewMat() { return m_viewMatrix; }

		inline glm::mat4 getOrthoProjMat() { return m_orthoProjmat; }

		inline glm::mat4 getPerspProjMat() { return m_perspProjmat; }

		void setViewMat(glm::mat4 _view) { m_viewMatrix = _view; }

		void setOrthoProjMat(glm::mat4 _proj) { m_orthoProjmat = _proj; }

		void setPerspProjMat(glm::mat4 _proj) { m_perspProjmat = _proj; }

		inline void setPos(glm::vec3 _pos) { m_cameraPos = _pos; }

		glm::vec2 getMouse();

		void onTick() override;

		void initialise();

		bool m_isOrtho;

		glm::mat4 m_viewMatrix;
		
		glm::mat4 m_orthoProjmat;

		glm::mat4 m_perspProjmat;

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