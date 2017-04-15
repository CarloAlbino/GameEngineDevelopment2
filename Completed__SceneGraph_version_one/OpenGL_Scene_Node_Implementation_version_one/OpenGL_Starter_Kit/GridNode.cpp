#include "GridNode.h"

GridNode::GridNode(float x, float y, NodeType type)
{
	m_x = x;
	m_y = y;
	m_nodeType = type;
}

GridNode::~GridNode()
{
}

void GridNode::SetPosition(float x, float y)
{
	m_x = x;
	m_y = y;
}

void GridNode::SetNodeType(NodeType type)
{
	m_nodeType = type;
}

float GridNode::x()
{
	return m_x;
}

float GridNode::y()
{
	return m_y;
}

NodeType GridNode::GetNodeType()
{
	return m_nodeType;
}

void GridNode::AddConnection(GridNode* node)
{
	m_connectedNodes.push_back(node);
}

float GridNode::DistanceToNode(GridNode* node)
{
	return sqrt( pow(node->x() - m_x, 2) + pow(node->y() - m_y, 2) );
}

GridNode* GridNode::GetConnectedNode(int index)
{
	if (index < m_connectedNodes.size())
		return m_connectedNodes[index];
	else
		return nullptr;
}