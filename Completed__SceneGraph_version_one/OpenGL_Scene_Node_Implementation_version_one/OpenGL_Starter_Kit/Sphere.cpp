#include "Sphere.h"

Sphere::Sphere(glm::mat4 transformation, float scale, float radius) : SceneNode(transformation, scale)
{
	m_rings = 10;
	m_sectors = 15;
	m_radius = radius;
}

Sphere::Sphere(glm::mat4 transformation, glm::vec3 scale, float radius)
	: SceneNode(transformation, scale)
{
	m_rings = 10;
	m_sectors = 15;
	m_radius = radius;
}

void Sphere::Draw()
{
	CalculateSphereCoordinates();

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, &m_vertices[0]);
	glNormalPointer(GL_FLOAT, 0, &m_normals[0]);
	glTexCoordPointer(2, GL_FLOAT, 0, &m_texcoords[0]);
	glDrawElements(GL_LINE_LOOP, m_indices.size(), GL_UNSIGNED_SHORT, &m_indices[0]);
}

/*
*	Formula for sphere coordinates taken from stackoverflow user datenwolf.
*	Credits go to them.
*	Can be found here: http://stackoverflow.com/questions/5988686/creating-a-3d-sphere-in-opengl-using-visual-c
*/

void Sphere::CalculateSphereCoordinates()
{
	float const R = 1. / (float)(m_rings - 1);
	float const S = 1. / (float)(m_sectors - 1);
	int r, s;

	m_vertices.resize(m_rings * m_sectors * 3);
	m_normals.resize(m_rings * m_sectors * 3);
	m_texcoords.resize(m_rings * m_sectors * 2);
	std::vector<GLfloat>::iterator v = m_vertices.begin();
	std::vector<GLfloat>::iterator n = m_normals.begin();
	std::vector<GLfloat>::iterator t = m_texcoords.begin();
	for (r = 0; r < m_rings; r++) for (s = 0; s < m_sectors; s++) {
		float const y = sin(-M_PI_2 + M_PI * r * R);
		float const x = cos(2 * M_PI * s * S) * sin(M_PI * r * R);
		float const z = sin(2 * M_PI * s * S) * sin(M_PI * r * R);

		*t++ = s*S;
		*t++ = r*R;

		*v++ = x * m_radius * m_scale.x;
		*v++ = y * m_radius * m_scale.y;
		*v++ = z * m_radius * m_scale.z;

		*n++ = x;
		*n++ = y;
		*n++ = z;
	}

	m_indices.resize(m_rings * m_sectors * 4);
	std::vector<GLushort>::iterator i = m_indices.begin();
	for (r = 0; r < m_rings - 1; r++) for (s = 0; s < m_sectors - 1; s++) {
		*i++ = r * m_sectors + s;
		*i++ = r * m_sectors + (s + 1);
		*i++ = (r + 1) * m_sectors + (s + 1);
		*i++ = (r + 1) * m_sectors + s;
	}
}
