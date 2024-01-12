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
		m_gain = 1.0f;

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
			if (m_speed > -15)
			{
				m_speed -= 3.5 * getCore()->getDT();
			}
		}

		float step = getCore()->getDT() * 2;
		if (getEntity()->getPosition().z > -12.827f)
		{
			if (getInput()->isKey(d) || getInput()->getLeftJStick().x < -0.4f)
			{
				Move(0, 0, -step);
			}
		}
		if (getEntity()->getPosition().z < -7.205f)
		{
			if (getInput()->isKey(a) || getInput()->getLeftJStick().x > 0.4f)
			{
				Move(0, 0, step);
			}
		}
	}

	void Player::onGUI()
	{
		if (getCore()->getGUI()->Button("../Textures/Buttons/HornDownButton.png", "../Textures/Buttons/HornUpButton.png", glm::vec2(300, 970), glm::vec2(200, 150)))
		{
			m_hornSound->playSound();
		}

		if (getCore()->getGUI()->Button("../Textures/Buttons/VolDownButtonDOWN.png", "../Textures/Buttons/VolDownButtonUP.png", glm::vec2(900, 970), glm::vec2(200, 150)))
		{
			if (m_gain > 0.0f)
				m_gain -= 0.1f;
			m_hornSound->setGain(m_gain);
			m_pigeonSound->setGain(m_gain);
		}
		if (getCore()->getGUI()->Button("../Textures/Buttons/VolUpButtonDOWN.png", "../Textures/Buttons/VolUpButtonUP.png", glm::vec2(600, 970), glm::vec2(200, 150)))
		{
			if (m_gain < 1.0f)
			{
				m_gain += 1.0f;
			}
			m_hornSound->setGain(m_gain);
			m_pigeonSound->setGain(m_gain);
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
