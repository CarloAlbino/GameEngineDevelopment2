#pragma once
#include "Primitives.h"

class StairCase : public SceneNode
{
public:
	StairCase(glm::mat4 transformation, float scale = 1.0f);
	StairCase(glm::mat4 tranformation, glm::vec3 scale);

	void draw() override;

};
