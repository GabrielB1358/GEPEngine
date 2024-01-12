#include "Player.h"
#include <GEPEngine/myEngine.h>
#include <GEPEngine/Input.h>
#include <GEPEngine/GUI.h>
#include <GEPEngine/ModelRenderer.h>
#include <GEPEngine/Rigidbody.h>

namespace GEPEngine
{

	Player::Player()
	{

	}

	void Player::initialise()
	{
		m_renderer = getEntity()->addComponent<GEPEngine::ModelRenderer>();
		m_renderer->setModel("../Models/Curuthers/curuthers.obj");
		m_renderer->setTexture("../Textures/Curuthers/Whiskers_diffuse.png");
		m_renderer->setShader("../Shaders/notGUI");

		m_hornSound = getEntity()->addComponent<GEPEngine::ALAudio>("../dixie_horn.ogg");
		m_pigeonSound = getEntity()->addComponent<GEPEngine::ALAudio>("../PigeonCoo.ogg");

		m_speed = -0.5;

		Scale(0.25, 0.25, 0.25);
		getEntity()->getTransform()->setRotation(glm::vec3(0, 90.0f, 0));
	}

	void Player::onTick()
	{
		if (getEntity()->getComponent<Rigidbody>()->getColliding())
		{
			if (getInput()->isKey(space) || getInput()->isKey(gpadA))
			{
				m_speed = 3;
			}
		}
		else
		{
			getEntity()->Move(glm::vec3(0, (m_speed * getEntity()->getCore()->getDT()), 0));
			if (m_speed > -50)
			{
				m_speed -= 3.5 * getCore()->getDT();
			}
		}

		float step = getCore()->getDT() * 2;
		if (getEntity()->getPosition().z > -12.827f)
		{
			if (getInput()->isKey(d))
			{
				Move(0, 0, -step);
			}
		}
		if (getEntity()->getPosition().z < -7.205f)
		{
			if (getInput()->isKey(a))
			{
				Move(0, 0, step);
			}
		}
	}

	void Player::onGUI()
	{
		if (getCore()->getGUI()->Button("../Textures/Buttons/DownButton.png", "../Textures/Buttons/UpButton.png", glm::vec2(800, 800), glm::vec2(200, 150)))
		{
			m_hornSound->playSound();
		}
	}

	void Player::Move(float _x, float _y, float _z)
	{
		getEntity()->getTransform()->Move(glm::vec3(_x, _y, _z));
	}

	void Player::Scale(float _x, float _y, float _z)
	{
		getEntity()->getTransform()->setScale(glm::vec3(_x, _y, _z));
	}

	void Player::onKill()
	{

	}

}
