#include "Cube.h"

Cube::Cube(glm::mat4 transformation, float scale, float side) : SceneNode(transformation, scale)
{
	m_side = side;
}

Cube::Cube(glm::mat4 transformation, glm::vec3 scale, float side)
	: SceneNode(transformation, scale)
{
	m_side = side;
}

void Cube::Draw()
{
	glBegin(GL_LINE_LOOP);

	float xPoint = m_side / 2 * m_scale.x;
	float yPoint = m_side / 2 * m_scale.y;
	float zPoint = m_side / 2 * m_scale.z;

	// Front face
	glVertex3f(-xPoint, -yPoint, -zPoint);	// Left, Bottom, Front
	glVertex3f(xPoint, -yPoint, -zPoint);	// Right, Bottom, Front
	glVertex3f(xPoint, yPoint, -zPoint);	// Right, Top, Front
	glVertex3f(-xPoint, yPoint, -zPoint);	// Left, Top, Front
	glVertex3f(-xPoint, -yPoint, -zPoint);	// Left, Bottom, Front

	// Left face
	glVertex3f(-xPoint, -yPoint, zPoint);	// Left, Bottom, Back
	glVertex3f(-xPoint, yPoint, zPoint);	// Left, Top, Back
	glVertex3f(-xPoint, yPoint, -zPoint);	// Left, Top, Front
	glVertex3f(-xPoint, yPoint, zPoint);	// Left, Top, Back

	// Top face
	glVertex3f(xPoint, yPoint, zPoint);	// Right, Top, Back
	glVertex3f(xPoint, yPoint, -zPoint);	// Right, Top, Front
	glVertex3f(xPoint, yPoint, zPoint);	// Right, Top, Back

	// Right face
	glVertex3f(xPoint, -yPoint, zPoint);	// Right, Bottom, Back
	glVertex3f(xPoint, -yPoint, -zPoint);	// Right, Bottom, Front
	glVertex3f(xPoint, -yPoint, zPoint);	// Right, Bottom, Back

	// Back and bottom face
	glVertex3f(-xPoint, -yPoint, zPoint);	// Left, Bottom, Back

	glEnd();
}

float Cube::GetSide()
{
	return m_side;
}
