#pragma once
#include "Square.h"

class Tank : public SceneNode
{
public:
	Tank::Tank(glm::mat4 transformation, float scale = 1.0f);

	void Draw() override;

private:
	float m_scale;

};
