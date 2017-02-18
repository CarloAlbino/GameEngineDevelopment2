#pragma once
#include "SceneNode.h"

class Cone : public SceneNode
{
public:
	Cone(glm::mat4 transformation, float scale);
	void draw(float scale) override;
};