#include "Tank.h"

Tank::Tank(glm::mat4 aTransformation, float scale) : SceneNode(aTransformation, scale)
{
	m_scale = scale;
}

void Tank::Draw()
{
	Square body = Square(glm::mat4(1.0f), m_scale);
	body.SetColor(m_red, m_green, m_blue);
	
	float wheel_offset = m_scale / 2.0f;
	Square w1 = Square(glm::translate(glm::mat4(1.0), glm::vec3(-wheel_offset, -wheel_offset, 0.0f)), m_scale/5.0f);
	w1.SetColor(m_red, m_green, m_blue);
	Square w2 = Square(glm::translate(glm::mat4(1.0), glm::vec3(wheel_offset, wheel_offset, 0.0f)), m_scale / 5.0f);
	w2.SetColor(m_red, m_green, m_blue);
	Square w3 = Square(glm::translate(glm::mat4(1.0), glm::vec3(-wheel_offset, wheel_offset, 0.0f)), m_scale / 5.0f);
	w3.SetColor(m_red, m_green, m_blue);
	Square w4 = Square(glm::translate(glm::mat4(1.0), glm::vec3(wheel_offset, -wheel_offset, 0.0f)), m_scale / 5.0f);
	w4.SetColor(m_red, m_green, m_blue);
	
	body.AddChild(&w1);
	body.AddChild(&w2);
	body.AddChild(&w3);
	body.AddChild(&w4);

	body.Render();
}


