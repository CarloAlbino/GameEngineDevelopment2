#pragma once
#include "SceneNode.h"

class Square : public SceneNode
{
public:
	Square::Square(glm::mat4 transformation, float scale, float side = 1.0f);
	Square::Square(glm::mat4 transformation, glm::vec2 scale, float side = 1.0f);

	void draw() override;

private:
	float m_side;
};