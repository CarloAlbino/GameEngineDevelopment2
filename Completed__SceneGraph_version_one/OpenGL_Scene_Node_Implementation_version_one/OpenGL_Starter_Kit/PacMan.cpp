#include "PacMan.h"
#include "Circle.h"

PacMan::PacMan(GridNode* startNode, float xPos, float yPos, glm::mat4 transformation, float scale, float radius)
	: SceneNode(transformation, scale)
{
	m_currentNode = startNode;
	m_currentDirection = None;
	m_x = startNode->x();
	m_y = startNode->y();

	m_radius = radius;
	m_moveStep = 0.07f;
	m_frameCount = 0;

	m_pacman = new Circle(glm::translate(glm::mat4(1.0), glm::vec3(m_x, m_y, 0.0f)), 1, m_radius);
	this->AddChild(m_pacman);
}

PacMan::~PacMan()
{
}

void PacMan::Update(float deltaTime)
{
	//printf("%f\n", m_frameCount);
	if (m_currentDirection != None)
	{
		if (m_frameCount <= 0)
		{
			//printf("Dir %i\n", (int)m_currentDirection);
			GridNode* nextNode = m_currentNode->GetConnectedNode((int)m_currentDirection);
			//printf("%i\n", (int)nextNode->GetNodeType());
			if (nextNode != nullptr && nextNode->GetNodeType() != Wall)
			{
				m_currentNode = nextNode;
				// Pickup dot
				if (m_currentNode->GetNodeType() == Dot)
				{
					m_currentNode->SetNodeType(Empty);
				}
			}
			m_x = m_currentNode->x();
			m_y = m_currentNode->y();

			m_frameCount = m_moveStep;
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
	m_pacman = new Circle(glm::translate(glm::mat4(1.0), glm::vec3(m_x, m_y, 0.0f)), 1, m_radius);
	m_pacman->SetColor(1, 1, 0);
	this->RemoveChild(0);
	this->AddChild(m_pacman);
}

void PacMan::SetDirection(Direction dir)
{
	//printf("Setting dir %i", dir);
	m_currentDirection = dir;
}

float PacMan::x()
{
	return m_x;
}

float PacMan::y()
{
	return m_y;
}

GridNode * PacMan::GetNode()
{
	return m_currentNode;
}
