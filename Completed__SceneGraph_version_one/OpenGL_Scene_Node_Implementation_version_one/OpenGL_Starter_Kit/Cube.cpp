#include "Cube.h"

Cube::Cube(glm::mat4 transformation, float scale) : SceneNode(transformation, scale)
{
}

void Cube::draw(float scale)
{
	glBegin(GL_LINE_LOOP);

	// Front face
	glVertex3f(-scale / 2, -scale / 2, -scale / 2);	// Left, Bottom, Front
	glVertex3f(scale / 2, -scale / 2, -scale / 2);	// Right, Bottom, Front
	glVertex3f(scale / 2, scale / 2, -scale / 2);	// Right, Top, Front
	glVertex3f(-scale / 2, scale / 2, -scale / 2);	// Left, Top, Front
	glVertex3f(-scale / 2, -scale / 2, -scale / 2);	// Left, Bottom, Front

	// Left face
	glVertex3f(-scale / 2, -scale / 2, scale / 2);	// Left, Bottom, Back
	glVertex3f(-scale / 2, scale / 2, scale / 2);	// Left, Top, Back
	glVertex3f(-scale / 2, scale / 2, -scale / 2);	// Left, Top, Front
	glVertex3f(-scale / 2, scale / 2, scale / 2);	// Left, Top, Back

	// Top face
	glVertex3f(scale / 2, scale / 2, scale / 2);	// Right, Top, Back
	glVertex3f(scale / 2, scale / 2, -scale / 2);	// Right, Top, Front
	glVertex3f(scale / 2, scale / 2, scale / 2);	// Right, Top, Back

	// Right face
	glVertex3f(scale / 2, -scale / 2, scale / 2);	// Right, Bottom, Back
	glVertex3f(scale / 2, -scale / 2, -scale / 2);	// Right, Bottom, Front
	glVertex3f(scale / 2, -scale / 2, scale / 2);	// Right, Bottom, Back

	// Back and bottom face
	glVertex3f(-scale / 2, -scale / 2, scale / 2);	// Left, Bottom, Back

	glEnd();
}
