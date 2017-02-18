#pragma once
#include "SceneNode.h"

class Sphere : public SceneNode
{
public:
	Sphere(glm::mat4 transformation, float scale);
	void draw(float scale) override;

protected:
	void CalculateSphereCoordinates();

protected:
	std::vector<GLfloat> vertices;
	std::vector<GLfloat> normals;
	std::vector<GLfloat> texcoords;
	std::vector<GLushort> indices;

	unsigned int rings;
	unsigned int sectors;

};