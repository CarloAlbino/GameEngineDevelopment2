#include "Cylinder.h"

Cylinder::Cylinder(glm::mat4 transformation, float scale) : SceneNode(transformation, scale)
{
}

void Cylinder::draw(float scale)
{
	float radius = scale / 2;
	float halfLength = scale / 2;
	float slices = 24;

	float theta = 0;

	if(slices != 0)
		theta = 360 / slices * (M_PI / 180);

	glBegin(GL_LINE_LOOP);

	for (int i = 0; i < slices; i++) {
		float angle = theta * i;
		// Top
		glVertex3f(0.0, halfLength, 0.0);
		glVertex3f(radius * cos(angle), halfLength, radius * sin(angle));
		glVertex3f(radius * cos(angle + theta), halfLength, radius * sin(angle + theta));
		// Bottom
		glVertex3f(radius * cos(angle + theta), -halfLength, radius * sin(angle + theta));
		glVertex3f(radius * cos(angle), -halfLength, radius * sin(angle));
		glVertex3f(0.0, -halfLength, 0.0);
	}
	glEnd();

}
