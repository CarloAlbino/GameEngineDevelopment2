#pragma once
#include "SceneNode.h"

class Sphere : public SceneNode
{
public:
	Sphere(glm::mat4 transformation, float scale, float radius = 0.5f);
	Sphere(glm::mat4 transformation, glm::vec3 scale, float radius = 0.5f);
	void draw() override;

protected:
	void CalculateSphereCoordinates();

protected:
	std::vector<GLfloat> vertices;
	std::vector<GLfloat> normals;
	std::vector<GLfloat> texcoords;
	std::vector<GLushort> indices;

	unsigned int rings;
	unsigned int sectors;

	float m_radius;

};