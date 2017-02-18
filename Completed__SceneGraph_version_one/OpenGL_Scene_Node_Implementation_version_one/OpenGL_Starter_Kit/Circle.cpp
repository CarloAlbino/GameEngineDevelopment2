#include "Circle.h"

Circle::Circle(glm::mat4 transformation, float scale) : SceneNode(transformation, scale)
{
}

void Circle::draw(float scale)
{
	float radius = scale / 2;
	float slices = 36;

	float theta = 0;

	if (slices != 0)
		theta = 360 / slices * (M_PI / 180);

	glBegin(GL_LINE_LOOP);

	for (int i = 0; i < slices; i++) {
		float angle = theta * i;
		glVertex2f(radius * cos(angle + theta), radius * sin(angle + theta));
	}
	glEnd();
}
