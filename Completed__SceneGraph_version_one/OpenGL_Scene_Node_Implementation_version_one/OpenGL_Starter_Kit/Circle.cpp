#include "Circle.h"

Circle::Circle(glm::mat4 transformation, float scale, float radius) : SceneNode(transformation, scale)
{
	m_radius = radius;
}

Circle::Circle(glm::mat4 transformation, glm::vec2 scale, float radius)
	:SceneNode(transformation, scale)
{
	m_radius = radius;
}

void Circle::Draw()
{
	float slices = 36;

	float theta = 0;

	if (slices != 0)
		theta = 360 / slices * (M_PI / 180);

	glBegin(GL_TRIANGLE_FAN);//GL_LINE_LOOP);

	for (int i = 0; i < slices; i++) {
		float angle = theta * i;
		glVertex2f(m_radius * cos(angle + theta) * m_scale.x, m_radius * sin(angle + theta) * m_scale.y);
	}

	glEnd();
}
