#pragma once

#include "SceneNode.h"
#include "Square.h"

class Tank : public SceneNode
{
public:
	Tank::Tank(glm::mat4 transformation, float scale = 1.0f);

	void draw() override;

private:
	float m_scale;
};
