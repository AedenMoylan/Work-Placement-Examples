#pragma once
#include <SFML/Graphics.hpp>
#include "Obstacle.h"
#include <iostream>
#include "Cell.h"
#include <queue>
class Grid
{
	const static int ROWS = 42;
	const static int COLUMNS = 34;

	const float cellWidth = 25.0f;
	const float cellHeight = 25.0f;

	const static int arraySize = 12;
	sf::RectangleShape grid[ROWS][COLUMNS];

	sf::Vector2f obstacleTopLeft[arraySize];
	sf::Vector2f obstacleTopRight[arraySize];
	sf::Vector2f obstacleBottomLeft[arraySize];
	sf::Vector2f obstacleBottomRight[arraySize];

	std::vector<Cell> m_cells;
	Cell childCellId;
	std::vector<int> m_impassableCells;
	
public:
	Grid();

	void init();
	void draw(sf::RenderWindow& window);
	void markImpassableCells(Obstacle& myObstacle);
	void neighbours(int t_row , int t_col);
	std::vector<int>breadthFirst(int t_startCellId, int t_destCellId);
	std::vector<Cell> getCells();
};

