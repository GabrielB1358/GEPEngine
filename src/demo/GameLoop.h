#pragma once
#include <iostream>
#include "Player.h"
#include "Floor.h"

#include <GEPEngine/Rigidbody.h>
#include <GEPEngine/Texture.h>
#include <GEPEngine/Model.h>
#include <GEPEngine/Shader.h>
#include <GEPEngine/ALAudio.h>
#include <GEPEngine/Camera.h>



namespace GEPEngine
{
	struct billboard;
	struct GameLoop : Component
	{

		void initialise();

		void onTick() override;

		std::shared_ptr<Core> m_core;

		std::shared_ptr<Entity> m_player;
		std::shared_ptr<Entity> m_floor;
		std::shared_ptr<Entity> m_billboard;
		std::shared_ptr<Entity> m_pointLight;
		std::shared_ptr<Entity> m_camera;

		float m_entityTime;
		float m_firstZSpawn;

		float angle;
		int enemyDeathNum;
	};
}

