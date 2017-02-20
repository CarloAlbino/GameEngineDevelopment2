#include "Square.h"

Square::Square(glm::mat4 transformation, float scale, float side) : SceneNode(transformation, scale)
{
	m_side = side;
}

Square::Square(glm::mat4 transformation, glm::vec2 scale, float side)
	: SceneNode(transformation, scale)
{
	m_side = side;
}

void Square::Draw()
{
	glBegin(GL_LINE_LOOP);

	float xPoint = m_side / 2 * m_scale.x;
	float yPoint = m_side / 2 * m_scale.y;

	glVertex2f(-xPoint, -yPoint);
	glVertex2f(xPoint, -yPoint);
	glVertex2f(xPoint, yPoint);
	glVertex2f(-xPoint, yPoint);

	glEnd();
}


