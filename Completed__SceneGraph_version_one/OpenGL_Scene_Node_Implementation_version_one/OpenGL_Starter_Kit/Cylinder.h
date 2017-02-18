#pragma once
#include "SceneNode.h"

class Cylinder : public SceneNode
{
public:
	Cylinder(glm::mat4 transformation, float scale);
	void draw(float scale) override;
};