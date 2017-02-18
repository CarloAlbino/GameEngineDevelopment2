#pragma once
#include "SceneNode.h"

class Circle : public SceneNode
{
public:
	Circle(glm::mat4 transformation, float scale);
	void draw(float scale) override;
};