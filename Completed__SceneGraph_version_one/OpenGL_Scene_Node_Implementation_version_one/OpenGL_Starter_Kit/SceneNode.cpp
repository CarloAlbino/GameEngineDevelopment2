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
	parent = nullptr;
	children = std::vector<SceneNode*>();

	m_scale.x = scale;
	m_scale.y = scale;
	m_scale.z = scale;

	r = 1.0f;
	g = 1.0f;
	b = 1.0f;
}

SceneNode::SceneNode(glm::mat4 transformation, glm::vec2 scale)
{
	m_transformation = transformation;
	parent = nullptr;
	children = std::vector<SceneNode*>();

	m_scale.x = scale.x;
	m_scale.y = scale.y;
	m_scale.z = 1.0f;

	r = 1.0f;
	g = 1.0f;
	b = 1.0f;
}

SceneNode::SceneNode(glm::mat4 transformation, glm::vec3 scale)
{
	m_transformation = transformation;
	parent = nullptr;
	children = std::vector<SceneNode*>();

	m_scale = scale;

	r = 1.0f;
	g = 1.0f;
	b = 1.0f;
}

void SceneNode::setColor(float R, float G, float B)
{
	r = R;
	g = G;
	b = B;
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


void SceneNode::setParent(SceneNode* p)
{
	parent = p;
}

void SceneNode::addChild(SceneNode* child)
{
	children.push_back(child);
	(*child).setParent(this);
}

glm::mat4 SceneNode::getTransformationMatrix()
{
	return m_transformation;
}

std::vector<SceneNode*> SceneNode::getChildren()
{
	return children;
}
SceneNode* SceneNode::getParent()
{
	return parent;
}

void SceneNode::render()
{
	//Step One: getMyTransformation
	glm::mat4 transf = getTransformationMatrix();
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
	glColor3f(r, g, b);
	draw();

	//Step Four: Render My Children
	for (int i = 0; i < children.size(); i++)
	{
		SceneNode* tmp = children.at(i);
		(*tmp).render();
	}

	//Final Step: glPopMatrix()
	glPopMatrix();

	return;

}


