#ifndef SCENENODE_HEADER
#define SCENENODE_HEADER
#define _USE_MATH_DEFINES

#include "glm\glm.hpp"
#include <glm\gtx\matrix_decompose.hpp>
#include "glm\gtc\matrix_transform.hpp"
#include "GL\glut.h"

#include <vector>
#include <cmath>

class SceneNode
{
public:
	//Constructors
	SceneNode(glm::mat4 transformation, float scale);
	SceneNode(glm::mat4 transformation, glm::vec2 scale);
	SceneNode(glm::mat4 transformation, glm::vec3 scale);

	//Methods
	void SceneNode::AddChild(SceneNode*);
	void SceneNode::SetColor(float r, float g, float b);
	void SetTransform(glm::mat4 transformation);
	void SetScale(float x, float y, float z = 1.0f);
	void SetScale(glm::vec2 scale);
	void SetScale(glm::vec3 scale);
	glm::mat4 SceneNode::GetTransformationMatrix();
	std::vector<SceneNode*> GetChildren();
	SceneNode* SceneNode::GetParent();
	void SceneNode::SetParent(SceneNode* p);
	void SceneNode::Render();
	virtual void SceneNode::Draw() = 0;

protected:
	std::vector<SceneNode*> m_children;
	SceneNode* m_parent;
	glm::mat4 m_transformation;
	float m_red, m_green, m_blue;
	glm::vec3 m_scale;

};
#endif // !SCENENODE_HEADER