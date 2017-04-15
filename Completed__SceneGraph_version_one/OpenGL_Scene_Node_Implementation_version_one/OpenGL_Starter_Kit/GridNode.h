#pragma once
#include <vector>

enum NodeType
{
	Empty, 
	Wall, 
	Dot
};

class GridNode
{
public:
	GridNode(float x, float y, NodeType type = Empty);
	~GridNode();

	void SetPosition(float x, float y);
	void SetNodeType(NodeType type);

	float x();
	float y();
	NodeType GetNodeType();

	void AddConnection(GridNode* node);
	float DistanceToNode(GridNode* node);
	GridNode* GetConnectedNode(int index);

private:
	NodeType m_nodeType;

	float m_x;
	float m_y;

	std::vector<GridNode*> m_connectedNodes;
};
