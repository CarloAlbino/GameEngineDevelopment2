#pragma once
#include "SceneNode.h"

class Circle : public SceneNode
{
public:
	Circle(glm::mat4 transformation, float scale = 1.0f, float radius = 0.5f);
	Circle(glm::mat4 transformation, glm::vec2 scale, float radius = 0.5f);

	void draw() override;

private:
	float m_radius;
};