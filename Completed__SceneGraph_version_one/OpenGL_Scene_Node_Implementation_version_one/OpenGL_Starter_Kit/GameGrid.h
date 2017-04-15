#pragma once
#include <fstream>
#include <stdio.h>
#include <vector>
#include "GridNode.h"
#include "SceneNode.h"

class GameGrid : public SceneNode
{
public:
	GameGrid(char* mapFile, glm::mat4 transformation, float scale = 1);
	~GameGrid();

	GridNode* GetNodeAt(int x, int y);
	int GetWidth();
	int GetHeight();

	void Draw() override;

private:
	std::vector<std::vector<GridNode*>> m_grid;

	int m_width;
	int m_height;

};