#pragma once
#include "SceneNode.h"

class Triangle : public SceneNode
{
public:
	Triangle::Triangle(glm::mat4 transformation, float scale, float height = 1.0f);
	Triangle::Triangle(glm::mat4 transformation, glm::vec2 scale, float height = 1.0f);

	void draw() override;

private:
	float m_height;
};