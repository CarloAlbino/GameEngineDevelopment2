#include "Cylinder.h"

Cylinder::Cylinder(glm::mat4 transformation, float scale, float radius, float height) : SceneNode(transformation, scale)
{
	m_radius = radius;
	m_height = height;
}

Cylinder::Cylinder(glm::mat4 transformation, glm::vec3 scale, float radius, float height)
	:SceneNode(transformation, scale)
{
	m_radius = radius;
	m_height = height;
}

void Cylinder::Draw()
{
	float halfLength = m_height / 2 * m_scale.y;
	float slices = 24;

	float theta = 0;

	if(slices != 0)
		theta = 360 / slices * (M_PI / 180);

	glBegin(GL_LINE_LOOP);

	for (int i = 0; i < slices; i++) {
		float angle = theta * i;
		// Top
		glVertex3f(0.0, halfLength, 0.0);
		glVertex3f(m_radius * cos(angle) * m_scale.x, halfLength, m_radius * sin(angle) * m_scale.z);
		glVertex3f(m_radius * cos(angle + theta) * m_scale.x, halfLength, m_radius * sin(angle + theta) * m_scale.z);
		// Bottom
		glVertex3f(m_radius * cos(angle + theta) * m_scale.x, -halfLength, m_radius * sin(angle + theta) * m_scale.z);
		glVertex3f(m_radius * cos(angle) * m_scale.x, -halfLength, m_radius * sin(angle) * m_scale.z);
		glVertex3f(0.0, -halfLength, 0.0);
	}

	glEnd();

}
