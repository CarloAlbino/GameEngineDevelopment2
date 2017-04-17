#pragma once
#include "GridNode.h"
#include "Circle.h"

enum Direction
{
	Up, 
	Down, 
	Left,
	Right,
	None
};

class PacMan : public SceneNode
{
public:
	PacMan(GridNode* startNode, float xPos, float yPos, glm::mat4 transformation, float scale, float radius);
	~PacMan();

	void Update(float deltaTime) override;
	void Draw() override;

	void SetDirection(Direction dir);
	float x();
	float y();
	GridNode* GetNode();

private:
	Direction m_currentDirection;
	GridNode* m_currentNode;
	float m_x;
	float m_y;

	Circle* m_pacman;
	float m_radius;
	float m_moveStep;
	float m_frameCount;

};
