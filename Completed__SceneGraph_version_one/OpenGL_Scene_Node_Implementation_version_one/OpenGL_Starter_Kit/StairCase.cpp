#include "StairCase.h"

StairCase::StairCase(glm::mat4 transformation, float scale)
	: SceneNode(transformation, scale)
{
}

StairCase::StairCase(glm::mat4 tranformation, glm::vec3 scale)
	: SceneNode(tranformation, scale)
{
}

void StairCase::Draw()
{
	float stepWidth = 0.13f;
	float xTranslation = stepWidth / 2 * m_scale.x;
	float yTranslation = stepWidth * m_scale.y;

	// Bottom step
	Cube body = Cube(glm::mat4(1.0f), m_scale);
	body.SetColor(m_red, m_green, m_blue);
	body.SetScale(m_scale.x, stepWidth * m_scale.y, m_scale.z);

	// The next steps
	Cube s1 = Cube(glm::translate(glm::mat4(1.0), glm::vec3(xTranslation, yTranslation, 0.0f)), m_scale);
	s1.SetColor(m_red, m_green, m_blue);
	s1.SetScale(m_scale.x - stepWidth * m_scale.x, stepWidth * m_scale.y, m_scale.z);
	Cube s2 = Cube(glm::translate(glm::mat4(1.0), glm::vec3(xTranslation * 2, yTranslation * 2, 0.0f)), m_scale);
	s2.SetColor(m_red, m_green, m_blue);
	s2.SetScale(m_scale.x - stepWidth * 2 * m_scale.x, stepWidth * m_scale.y, m_scale.z);
	Cube s3 = Cube(glm::translate(glm::mat4(1.0), glm::vec3(xTranslation * 3, yTranslation * 3, 0.0f)), m_scale);
	s3.SetColor(m_red, m_green, m_blue);
	s3.SetScale(m_scale.x - stepWidth * 3 * m_scale.x, stepWidth * m_scale.y, m_scale.z);
	Cube s4 = Cube(glm::translate(glm::mat4(1.0), glm::vec3(xTranslation * 4, yTranslation * 4, 0.0f)), m_scale);
	s4.SetColor(m_red, m_green, m_blue);
	s4.SetScale(m_scale.x - stepWidth * 4 * m_scale.x, stepWidth * m_scale.y, m_scale.z);
	Cube s5 = Cube(glm::translate(glm::mat4(1.0), glm::vec3(xTranslation * 5, yTranslation * 5, 0.0f)), m_scale);
	s5.SetColor(m_red, m_green, m_blue);
	s5.SetScale(m_scale.x - stepWidth * 5 * m_scale.x, stepWidth * m_scale.y, m_scale.z);

	// Attach all the steps as children
	body.AddChild(&s1);
	body.AddChild(&s2);
	body.AddChild(&s3);
	body.AddChild(&s4);
	body.AddChild(&s5);

	body.Render();
}
