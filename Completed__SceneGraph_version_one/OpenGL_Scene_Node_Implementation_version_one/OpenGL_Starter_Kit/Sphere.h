#pragma once
#include "SceneNode.h"

class Sphere : public SceneNode
{
public:
	Sphere(glm::mat4 transformation, float scale, float radius = 0.5f);
	Sphere(glm::mat4 transformation, glm::vec3 scale, float radius = 0.5f);
	void Draw() override;

protected:
	void CalculateSphereCoordinates();

protected:
	std::vector<GLfloat> m_vertices;
	std::vector<GLfloat> m_normals;
	std::vector<GLfloat> m_texcoords;
	std::vector<GLushort> m_indices;

	unsigned int m_rings;
	unsigned int m_sectors;

	float m_radius;

};