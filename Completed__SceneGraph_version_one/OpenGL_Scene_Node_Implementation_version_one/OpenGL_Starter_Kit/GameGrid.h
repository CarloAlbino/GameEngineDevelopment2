#pragma once
#include <fstream>
#include <stdio.h>
#include <vector>
#include "GridNode.h"
#include "SceneNode.h"
#include "PacMan.h"
#include "Ghost.h"

class GameGrid : public SceneNode
{
public:
	GameGrid(char* mapFile, glm::mat4 transformation, float scale = 1);
	~GameGrid();

	GridNode* GetNodeAt(int x, int y);
	int GetWidth();
	int GetHeight();

	void Update(float deltaSeconds) override;
	void UpdateInput(char key, bool down) override;
	void Draw() override;

	void SetNodeConnections();

private:
	std::vector<std::vector<GridNode*>> m_grid;
	GridNode* m_fillerNode;

	PacMan* m_pacman;
	std::vector<Ghost*> m_ghosts;

	int m_width;
	int m_height;

};