#include "StairCase.h"

StairCase::StairCase(glm::mat4 transformation, float scale)
	: SceneNode(transformation, scale)
{
}

StairCase::StairCase(glm::mat4 tranformation, glm::vec3 scale)
	: SceneNode(tranformation, scale)
{
}

void StairCase::draw()
{
	float stepWidth = 0.13f;
	float xTranslation = stepWidth / 2 * m_scale.x;
	float yTranslation = stepWidth * m_scale.y;

	// Bottom step
	Cube body = Cube(glm::mat4(1.0f), m_scale);
	body.setColor(r, g, b);
	body.SetScale(m_scale.x, stepWidth * m_scale.y, m_scale.z);

	// The next steps
	Cube s1 = Cube(glm::translate(glm::mat4(1.0), glm::vec3(xTranslation, yTranslation, 0.0f)), m_scale);
	s1.setColor(r, g, b);
	s1.SetScale(m_scale.x - stepWidth * m_scale.x, stepWidth * m_scale.y, m_scale.z);
	Cube s2 = Cube(glm::translate(glm::mat4(1.0), glm::vec3(xTranslation * 2, yTranslation * 2, 0.0f)), m_scale);
	s2.setColor(r, g, b);
	s2.SetScale(m_scale.x - stepWidth * 2 * m_scale.x, stepWidth * m_scale.y, m_scale.z);
	Cube s3 = Cube(glm::translate(glm::mat4(1.0), glm::vec3(xTranslation * 3, yTranslation * 3, 0.0f)), m_scale);
	s3.setColor(r, g, b);
	s3.SetScale(m_scale.x - stepWidth * 3 * m_scale.x, stepWidth * m_scale.y, m_scale.z);
	Cube s4 = Cube(glm::translate(glm::mat4(1.0), glm::vec3(xTranslation * 4, yTranslation * 4, 0.0f)), m_scale);
	s4.setColor(r, g, b);
	s4.SetScale(m_scale.x - stepWidth * 4 * m_scale.x, stepWidth * m_scale.y, m_scale.z);
	Cube s5 = Cube(glm::translate(glm::mat4(1.0), glm::vec3(xTranslation * 5, yTranslation * 5, 0.0f)), m_scale);
	s5.setColor(r, g, b);
	s5.SetScale(m_scale.x - stepWidth * 5 * m_scale.x, stepWidth * m_scale.y, m_scale.z);

	// Attach all the steps as children
	body.addChild(&s1);
	body.addChild(&s2);
	body.addChild(&s3);
	body.addChild(&s4);
	body.addChild(&s5);

	body.render();
}
