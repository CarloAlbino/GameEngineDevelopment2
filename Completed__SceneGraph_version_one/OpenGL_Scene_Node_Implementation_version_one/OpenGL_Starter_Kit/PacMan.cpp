#include "PacMan.h"
#include "Circle.h"

PacMan::PacMan(GridNode* startNode, float xPos, float yPos, glm::mat4 transformation, float scale, float radius)
	: SceneNode(transformation, scale)
{
	m_currentNode = startNode;
	m_currentDirection = None;
	m_x = xPos;
	m_y = yPos;

	m_radius = radius;
	m_moveSpeed = 0.5f;
	m_frameCount = 0;
}

PacMan::~PacMan()
{
}

void PacMan::Update(float deltaTime)
{
	printf("%f\n", m_frameCount);
	if (m_currentDirection != None)
	{
		if (m_frameCount <= 0)
		{
			GridNode* nextNode = m_currentNode->GetConnectedNode((int)m_currentDirection);
			printf("%i\n", (int)nextNode->GetNodeType());
			if (nextNode != nullptr && nextNode->GetNodeType() != Wall)
			{
				m_currentNode = nextNode;
			}
			m_x = m_currentNode->x();
			m_y = m_currentNode->y();

			m_frameCount = m_moveSpeed;
		}
		else
		{
			m_frameCount -= deltaTime;
		}
	}
	else
	{
		m_frameCount = 0;
	}
}

void PacMan::Draw()
{
	Circle* body = new Circle(glm::translate(glm::mat4(1.0), glm::vec3(m_x, m_y, 0.0f)), 1, m_radius);
	body->SetColor(1, 1, 0);
	this->AddChild(body);
}

void PacMan::SetDirection(Direction dir)
{
	m_currentDirection = dir;
}
