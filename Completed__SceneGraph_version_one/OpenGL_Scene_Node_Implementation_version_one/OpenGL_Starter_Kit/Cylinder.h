#pragma once
#include "SceneNode.h"

class Cylinder : public SceneNode
{
public:
	Cylinder(glm::mat4 transformation, float scale , float radius = 0.5f, float height = 1.0f);
	Cylinder(glm::mat4 transformation, glm::vec3 scale , float radius = 0.5f, float height = 1.0f);

	void Draw() override;

private:
	float m_radius;
	float m_height;

};