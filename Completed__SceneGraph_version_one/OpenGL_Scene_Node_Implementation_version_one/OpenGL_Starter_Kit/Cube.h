#pragma once

#include "SceneNode.h"

class Cube : public SceneNode
{
public:
	Cube(glm::mat4 transformation, float scale, float side = 1.0f);
	Cube(glm::mat4 transformation, glm::vec3 scale, float side = 1.0f);

	void draw() override;

private:
	float m_side;

};