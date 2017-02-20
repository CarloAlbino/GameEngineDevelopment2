#include "SceneNode.h"
#pragma once
///////////////////////////////////////////////////////////////////////
//
// SceneNode.cpp
//
///////////////////////////////////////////////////////////////////////
using namespace std;

SceneNode::SceneNode(glm::mat4 transformation, float scale)
{
	m_transformation = transformation;
	m_parent = nullptr;
	m_children = std::vector<SceneNode*>();

	m_scale.x = scale;
	m_scale.y = scale;
	m_scale.z = scale;

	m_red = 1.0f;
	m_green = 1.0f;
	m_blue = 1.0f;
}

SceneNode::SceneNode(glm::mat4 transformation, glm::vec2 scale)
{
	m_transformation = transformation;
	m_parent = nullptr;
	m_children = std::vector<SceneNode*>();

	m_scale.x = scale.x;
	m_scale.y = scale.y;
	m_scale.z = 1.0f;

	m_red = 1.0f;
	m_green = 1.0f;
	m_blue = 1.0f;
}

SceneNode::SceneNode(glm::mat4 transformation, glm::vec3 scale)
{
	m_transformation = transformation;
	m_parent = nullptr;
	m_children = std::vector<SceneNode*>();

	m_scale = scale;

	m_red = 1.0f;
	m_green = 1.0f;
	m_blue = 1.0f;
}

void SceneNode::SetColor(float R, float G, float B)
{
	m_red = R;
	m_green = G;
	m_blue = B;
}

void SceneNode::SetTransform(glm::mat4 transformation)
{
	m_transformation = transformation;
}

void SceneNode::SetScale(float x, float y, float z)
{
	m_scale.x = x;
	m_scale.y = y;
	m_scale.z = z;
}

void SceneNode::SetScale(glm::vec2 scale)
{
	m_scale.x = scale.x;
	m_scale.y = scale.y;
	m_scale.z = 1.0f;
}

void SceneNode::SetScale(glm::vec3 scale)
{
	m_scale = scale;
}


void SceneNode::SetParent(SceneNode* p)
{
	m_parent = p;
}

void SceneNode::AddChild(SceneNode* child)
{
	m_children.push_back(child);
	(*child).SetParent(this);
}

glm::mat4 SceneNode::GetTransformationMatrix()
{
	return m_transformation;
}

std::vector<SceneNode*> SceneNode::GetChildren()
{
	return m_children;
}
SceneNode* SceneNode::GetParent()
{
	return m_parent;
}

void SceneNode::Render()
{
	//Step One: getMyTransformation
	glm::mat4 transf = GetTransformationMatrix();
	glm::vec3 myScale;
	glm::quat rotation;
	glm::vec3 translation;
	glm::vec3 skew;
	glm::vec4 perspective;
	glm::decompose(transf, myScale, rotation, translation, skew, perspective);

	//Step Two: glPushMatrix(My Transformation)
	glPushMatrix();
	glTranslatef(translation.x, translation.y, translation.z);

	float angle = 2 * acos(rotation.w);
	angle = angle * 180 / 3.14159265358979323846;
	float sqrtOfW = sqrt(1 - rotation.w * rotation.w);

	if (sqrtOfW != 0)
	{
		glRotatef(angle, rotation.x / sqrtOfW, rotation.y / sqrtOfW, rotation.z / sqrtOfW);
	}

	//Step Three: Draw myself
	glColor3f(m_red, m_green, m_blue);
	Draw();

	//Step Four: Render My Children
	for (int i = 0; i < m_children.size(); i++)
	{
		SceneNode* tmp = m_children.at(i);
		(*tmp).Render();
	}

	//Final Step: glPopMatrix()
	glPopMatrix();

	return;

}


