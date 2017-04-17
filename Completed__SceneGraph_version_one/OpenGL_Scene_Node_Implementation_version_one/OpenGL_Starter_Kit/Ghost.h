#pragma once
#include "Square.h"
#include "Circle.h"
#include "GridNode.h"
#include "PacMan.h"

class Ghost : public SceneNode
{
public:
	Ghost(GridNode* startNode, PacMan* pacman, float r, float g, float b, glm::mat4 transformation, float scale);
	~Ghost();

	void Update(float DeltaSeconds) override;
	void Draw() override;

	void DrawGhost();
	void AddGhostReference(Ghost* newGhost);

	float x();
	float y();

private:
	GridNode* m_currentNode;
	GridNode* m_prevNode;
	float m_x;
	float m_y;

	PacMan* m_pacman;
	std::vector<Ghost*> m_ghosts;

	float m_moveStep;
	float m_frameCount;

};