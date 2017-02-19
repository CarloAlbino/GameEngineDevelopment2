#ifndef SCENENODE_HEADER
#define SCENENODE_HEADER

#define _USE_MATH_DEFINES

#include "glm\glm.hpp"
#include <glm\gtx\matrix_decompose.hpp>
#include "glm\gtc\matrix_transform.hpp"
#include <vector>
#include "GL\glut.h"
#include <cmath>

class SceneNode
{
protected:
	std::vector<SceneNode*> children;
	SceneNode* parent;
	glm::mat4 m_transformation;
	float r, g, b;
	glm::vec3 m_scale;

public:
	//Constructor
	SceneNode(glm::mat4 transformation, float scale);
	SceneNode(glm::mat4 transformation, glm::vec2 scale);
	SceneNode(glm::mat4 transformation, glm::vec3 scale);

	//Methods
	void SceneNode::addChild(SceneNode*);
	void SceneNode::setColor(float r, float g, float b);
	void SetScale(float x, float y, float z = 1.0f);
	void SetScale(glm::vec2 scale);
	void SetScale(glm::vec3 scale);
	glm::mat4 SceneNode::getTransformationMatrix();
	std::vector<SceneNode*> getChildren();
	SceneNode* SceneNode::getParent();
	void SceneNode::setParent(SceneNode* p);
	void SceneNode::render();
	virtual void SceneNode::draw() = 0;

};
#endif // !SCENENODE_HEADER