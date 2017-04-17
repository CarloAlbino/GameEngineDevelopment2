#include "Ghost.h"

Ghost::Ghost(GridNode * startNode, PacMan * pacman, float r, float g, float b, glm::mat4 transformation, float scale)
	: SceneNode(transformation, scale)
{
	m_currentNode = startNode;
	m_x = startNode->x();
	m_y = startNode->y();

	m_moveStep = 0.15f;
	m_frameCount = 0;

	m_pacman = pacman;
	m_red = r;
	m_green = g;
	m_blue = b;

	DrawGhost();
}

Ghost::~Ghost()
{
}

void Ghost::Update(float DeltaSeconds)
{
	//printf("%f\n", m_frameCount);
	if (this->m_x != m_pacman->x() || this->m_y != m_pacman->y())
	{
		if (m_frameCount <= 0)
		{
			float shortestDistance = m_currentNode->DistanceToNode(m_pacman->GetNode());
			int dirToGo = -1;
			// Get the next closest node to Pacman
			for (int i = 0; i < 4; i++)
			{
				if (m_currentNode->GetConnectedNode(i)->GetNodeType() != Wall && m_currentNode->GetConnectedNode(i) != m_prevNode)
				{
					if (m_currentNode->GetConnectedNode(i)->DistanceToNode(m_pacman->GetNode()) < shortestDistance)
					{
						shortestDistance = m_currentNode->GetConnectedNode(i)->DistanceToNode(m_pacman->GetNode());

						// Don't go to a node that has another ghost on it
						bool isClear = true;
						for (int j = 0; j < m_ghosts.size(); j++)
						{
							if (m_currentNode->GetConnectedNode(i)->x() == m_ghosts[j]->x() &&
								m_currentNode->GetConnectedNode(i)->y() == m_ghosts[j]->y())
								isClear = false;
						}

						if(isClear)
							dirToGo = i;
					}
				}
				
			}

			// If no "best" direction, pick the first clear direction
			if (dirToGo == -1)
			{
				for (int i = 0; i < 4; i++)
				{
					if (m_currentNode->GetConnectedNode(i)->GetNodeType() != Wall)
					{
						bool isClear = true;
						for (int j = 0; j < m_ghosts.size(); j++)
						{
							if (m_currentNode->GetConnectedNode(i)->x() == m_ghosts[j]->x() &&
								m_currentNode->GetConnectedNode(i)->y() == m_ghosts[j]->y())
								isClear = false;
						}

						if (isClear)
						{
							dirToGo = i;
							break;
						}
					}
				}
			}

			// If there is still no clear path don't move, if there is move
			if (dirToGo > -1)
			{
				GridNode* nextNode = m_currentNode->GetConnectedNode(dirToGo);
				m_prevNode = m_currentNode;
				m_currentNode = nextNode;

				m_x = m_currentNode->x();
				m_y = m_currentNode->y();
			}

			m_frameCount = m_moveStep;
		}
		else
		{
			m_frameCount -= DeltaSeconds;
		}
	}
	//else
	//{
	//	m_frameCount = 0;
	//}
}

void Ghost::Draw()
{
	this->RemoveChildren();
	DrawGhost();
}

void Ghost::DrawGhost()
{
	Square* body = new Square(glm::translate(glm::mat4(1.0), glm::vec3(m_x, m_y, 0.0f)), 1, 0.085);
	body->SetColor(m_red, m_green, m_blue);
	this->AddChild(body);
	Circle* leftEye = new Circle(glm::translate(glm::mat4(1.0), glm::vec3(m_x - 0.02, m_y + 0.02, 0.0f)), 1, 0.01f);
	leftEye->SetColor(m_red, m_green, m_blue);
	this->AddChild(leftEye);
	Circle* rightEye = new Circle(glm::translate(glm::mat4(1.0), glm::vec3(m_x + 0.02, m_y + 0.02, 0.0f)), 1, 0.01f);
	rightEye->SetColor(m_red, m_green, m_blue);
	this->AddChild(rightEye);
}

void Ghost::AddGhostReference(Ghost * newGhost)
{
	m_ghosts.push_back(newGhost);
}

float Ghost::x()
{
	return m_x;
}

float Ghost::y()
{
	return m_y;
}
