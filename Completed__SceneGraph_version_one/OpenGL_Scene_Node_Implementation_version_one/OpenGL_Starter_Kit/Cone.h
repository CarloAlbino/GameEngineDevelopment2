#pragma once
#include "SceneNode.h"

class Cone : public SceneNode
{
public:
	Cone(glm::mat4 transformation, float scale, float radius = 0.5f, float height = 1.0f);
	Cone(glm::mat4 transformation, glm::vec3 scale, float radius = 0.5f, float height = 1.0f);

	void draw() override;

private:
	float m_radius;
	float m_height;

};