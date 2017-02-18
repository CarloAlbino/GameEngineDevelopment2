#pragma once

#include "SceneNode.h"

class Cube : public SceneNode
{
public:
	Cube(glm::mat4 transformation, float scale);
	void draw(float scale) override;
};