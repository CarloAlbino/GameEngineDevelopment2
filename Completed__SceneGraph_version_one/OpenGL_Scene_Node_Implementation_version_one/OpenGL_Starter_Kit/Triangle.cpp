#include "Triangle.h"

Triangle::Triangle(glm::mat4 aTransformation, float scale, float height) : SceneNode(aTransformation, scale)
{
	m_height = height;
}

Triangle::Triangle(glm::mat4 transformation, glm::vec2 scale, float height)
	: SceneNode(transformation, scale)
{
	m_height = height;
}

void Triangle::Draw()
{
	glBegin(GL_LINE_LOOP);

	float xPoint = m_height / 2 * m_scale.x;

	glVertex2f(-xPoint, -m_height / 3 * m_scale.y);
	glVertex2f(xPoint, -m_height / 2 * m_scale.y);
	glVertex2f(0, m_height * m_scale.y);

	glEnd();
}

