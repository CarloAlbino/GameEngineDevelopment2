#include "GameGrid.h"
#include <stdlib.h>
#include "Primitives.h"

GameGrid::GameGrid(char * mapFile, glm::mat4 transformation, float scale)
	: SceneNode(transformation, scale)
{
	//printf("Creating a new game grid\n");

	// Load the map file
	std::ifstream inFile;
	inFile.open(mapFile);

	// Check if file was opened
	if (!inFile)
	{
		printf("Unable to open %s", mapFile);
		exit(1); // Call system to stop
	}

	// Get the input from the file
	char input[8];
	int xIterator = 0;
	int yIterator = 0;
	while (inFile >> input)
	{
		//printf("%c", input);
		if (input[0] == 'x')	  // Get the width of the grid
		{
			//printf("%s: ", input);
			inFile >> input;
			m_width = atoi(input);
			//printf("%i\n", m_width);
		}
		else if (input[0] == 'y') // Get the height of the grid
		{
			//printf("%s: ", input);
			inFile >> input;
			m_height = atoi(input);
			//printf("%i\n", m_height);
		}
		else if (input[0] == 'n')  // The input is a node
		{
			// Create the nodes based on the positions read from the map file
			// Store values for a new node
			NodeType newType;
			float x;
			float y;

			// Get the type
			inFile >> input;
			switch (input[0])
			{
			case 'e':
			default:
				// Empty node
				newType = Empty;
				//printf("empty\n");
				break;
			case 'w':
				// Wall node
				newType = Wall;
				//printf("wall\n");
				break;
			case 'd':
				// Dot node
				newType = Dot;
				//printf("dot\n");
				break;
			}

			// Get the x position
			inFile >> input;
			x = atof(input);
			// Get the y position
			inFile >> input;
			y = atof(input);

			//printf("x pos: %f ", x);
			//printf("y pos: %f\n", y);

			// Create and attach the new node
			GridNode* newNode = new GridNode(x, y, newType);
			// If at the start of a new row create a new vector
			if (xIterator == 0)
			{
				m_grid.push_back(std::vector<GridNode*>());
			}
			// Add the node to the vector
			m_grid[yIterator].push_back(newNode);
			// Increment count
			xIterator++;
			// Reset the count
			if (xIterator == m_width)
			{
				yIterator++;
				xIterator = 0;
			}
		}
	}

	// Close file
	inFile.close();
	// Create a filler node, this is done so that each node has 4 connected node
	m_fillerNode = new GridNode(-1, -1, Wall);
	// Set all the node connections
	SetNodeConnections();
	
	// Create pacman
	m_pacman = new PacMan(GetNodeAt(9, 10), 1, 2, glm::mat4(1), 1, 0.04);
	this->AddChild(m_pacman);
	// Create Ghosts
	Ghost* inky = new Ghost(GetNodeAt(1, 1), m_pacman, 1.0f, 0.25f, 0.6f, glm::mat4(1), 1);
	m_ghosts.push_back(inky);
	this->AddChild(inky);
	Ghost* binky = new Ghost(GetNodeAt(17, 1), m_pacman, 0.0f, 0.75f, 1.0f, glm::mat4(1), 1);
	m_ghosts.push_back(binky);
	this->AddChild(binky);
	Ghost* dinky = new Ghost(GetNodeAt(1, 17), m_pacman, 1.0f, 0.5f, 0.0f, glm::mat4(1), 1);
	m_ghosts.push_back(dinky);
	this->AddChild(dinky);
	Ghost* Clyde = new Ghost(GetNodeAt(17, 17), m_pacman, 1.0f, 0.0f, 0.0f, glm::mat4(1), 1);
	m_ghosts.push_back(Clyde);
	this->AddChild(Clyde);

	// Give a reference to the other ghosts to each ghost ignoring itself
	for (int i = 0; i < m_ghosts.size(); i++)
	{
		for (int j = 0; j < m_ghosts.size(); j++)
		{
			if(i != j)
				m_ghosts[i]->AddGhostReference(m_ghosts[j]);
		}
	}
}

GameGrid::~GameGrid()
{
}

GridNode * GameGrid::GetNodeAt(int x, int y)
{
	if (y > -1 && y < m_height && x > -1 && x < m_width)
	{
		return m_grid.at(y).at(x);
	}
	else
	{
		return m_fillerNode;
	}
}

int GameGrid::GetWidth()
{
	return m_width;
}

int GameGrid::GetHeight()
{
	return m_height;
}

void GameGrid::Update(float deltaSeconds)
{
	m_pacman->Update(deltaSeconds);
	for (int i = 0; i < m_ghosts.size(); i++)
	{
		m_ghosts[i]->Update(deltaSeconds);
	}
}

void GameGrid::UpdateInput(char key, bool down)
{
	if (down)	// Key down
	{
		switch (key)
		{
		case 'w':
			m_pacman->SetDirection(Up);
			break;
		case 's':
			m_pacman->SetDirection(Down);
			break;
		case 'a':
			m_pacman->SetDirection(Left);
			break;
		case 'd':
			m_pacman->SetDirection(Right);
			break;
		default:
			//do nothing
			break;
		}
	}
	else // Key up
	{
		switch (key)
		{
		case 'w':
			break;
		case 's':
			break;
		case 'a':
			break;
		case 'd':
			break;
		default:
			//do nothing
			break;
		}
	}
}

void GameGrid::Draw()
{
	this->RemoveChildrenInRange(5, m_children.size() - 1);
	for (int width = 0; width < m_width; width++)
	{
		for (int height = 0; height < m_height; height++)
		{
			switch (GetNodeAt(width, height)->GetNodeType())
			{
			case Empty:
			default:
			{
				Square* newChildNode = new Square(glm::translate(glm::mat4(1.0),
					glm::vec3(GetNodeAt(width, height)->x(), GetNodeAt(width, height)->y(), 0.0f)),
					0.09);
				newChildNode->SetColor(0, 0, 0);
				this->AddChild(newChildNode);
			}
				break;
			case Wall:
			{
				Square* newChildNode = new Square(glm::translate(glm::mat4(1.0),
					glm::vec3(GetNodeAt(width, height)->x(), GetNodeAt(width, height)->y(), 0.0f)),
					0.1);
				newChildNode->SetColor(0, 0, 1);
				this->AddChild(newChildNode);
			}
				break;
			case Dot:
			{
				Circle* newChildNode = new Circle(glm::translate(glm::mat4(1.0),
					glm::vec3(GetNodeAt(width, height)->x(), GetNodeAt(width, height)->y(), 0.0f)),
					0.03);
				newChildNode->SetColor(1, 1, 1);
				this->AddChild(newChildNode);
			}
				break;
			}
		}
	}
}

void GameGrid::SetNodeConnections()
{
	for (int width = 0; width < m_width; width++)
	{
		for (int height = 0; height < m_height; height++)
		{
			// Add node above
			if (GetNodeAt(width, height - 1) != nullptr)
			{
				GetNodeAt(width, height)->AddConnection(GetNodeAt(width, height - 1));
			}
			else
			{
				GetNodeAt(width, height)->AddConnection(nullptr);
			}
			// Add node below
			if (GetNodeAt(width, height + 1) != nullptr)
			{
				GetNodeAt(width, height)->AddConnection(GetNodeAt(width, height + 1));
			}
			else
			{
				GetNodeAt(width, height)->AddConnection(nullptr);
			}
			// Add node to the left
			if (GetNodeAt(width - 1, height) != nullptr)
			{
				GetNodeAt(width, height)->AddConnection(GetNodeAt(width - 1, height));
			}
			else
			{
				GetNodeAt(width, height)->AddConnection(nullptr);
			}
			// Add node to the right
			if (GetNodeAt(width + 1, height) != nullptr)
			{
				GetNodeAt(width, height)->AddConnection(GetNodeAt(width + 1, height));
			}
			else
			{
				GetNodeAt(width, height)->AddConnection(nullptr);
			}
		}
	}
}
