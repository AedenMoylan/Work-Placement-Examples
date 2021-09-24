#include "Grid.h"

Grid::Grid()
{
	m_cells.resize(ROWS * COLUMNS);
	for (int i = 0; i < ROWS * COLUMNS; i++)
	{
		m_cells.at(i).setId(i);
	}

	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLUMNS; col++)
		{
			int index = col * ROWS + row;
			float rowOffset = row * cellHeight;
			float colOffset = col * cellWidth;

			m_cells.at(index).setCentre(sf::Vector2f(rowOffset + cellWidth/2, colOffset + cellHeight/2));
			neighbours(row,col); 
		}
	}
}

void Grid::init()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			grid[i][j].setSize(sf::Vector2f(cellWidth, cellHeight));

			grid[i][j].setPosition(i * 25, j * 25);

			grid[i][j].setOutlineThickness(1);

			grid[i][j].setOutlineColor(sf::Color(149, 33, 246, 60));

			grid[i][j].setFillColor(sf::Color::Transparent);
		}
	}

}

void Grid::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			window.draw(grid[i][j]);
		}
	}
}

void Grid::markImpassableCells(Obstacle& myObstacle)
{
	int cellID = 0;

	for (int i = 0; i < myObstacle.getMaxObstacles(); i++)
	{
		obstacleTopLeft[i] = myObstacle.getTopLeft(i);
		obstacleTopRight[i] = myObstacle.getTopRight(i);
		obstacleBottomLeft[i] = myObstacle.getBottomLeft(i);
		obstacleBottomRight[i] = myObstacle.getBottomRight(i);

		cellID = std::floor(obstacleTopLeft[i].x / cellWidth) + std::floor(obstacleTopLeft[i].y / cellHeight) * COLUMNS;
		
		m_cells.at(cellID).setPassable(false);

		cellID = std::floor(obstacleTopRight[i].x / cellWidth) + std::floor(obstacleTopRight[i].y / cellHeight) * COLUMNS;

		m_cells.at(cellID).setPassable(false);

		cellID = std::floor(obstacleBottomLeft[i].x / cellWidth) + std::floor(obstacleBottomLeft[i].y / cellHeight) * COLUMNS;

		m_cells.at(cellID).setPassable(false);

		cellID = std::floor(obstacleBottomRight[i].x / cellWidth) + std::floor(obstacleBottomRight[i].y / cellHeight) * COLUMNS;

		m_cells.at(cellID).setPassable(false);

	}
}

void Grid::neighbours(int t_row , int t_col)
{
	for (int direction = 0; direction < 9; direction++)
	{
		int n_row = t_row + ((direction % 3) - 1); // neighbour row
		int n_col = t_col + ((direction / 3) - 1);

		if (n_row >= 0 && n_row < ROWS && n_col >= 0 && n_col < COLUMNS)
		{
			int neighbourIndex = n_col * ROWS + n_row;
			int index = t_col * ROWS + t_row;

			m_cells.at(index).addNeighbours(neighbourIndex);
		}
	}
}

std::vector<int> Grid::breadthFirst(int t_startCellId, int t_destCellId)
{
	bool goalReached = false;
	std::queue<Cell> cellQueue;

	Cell startCell = m_cells.at(t_startCellId);
	cellQueue.emplace(startCell);
	m_cells.at(t_startCellId).setMarked(true);

	int childCellId;

	while (!cellQueue.empty() && goalReached == false)
	{
		for (int index = 0; index < cellQueue.front().neighbours().size() && !goalReached; index++)
		{
			childCellId = cellQueue.front().neighbours().at(index);

			Cell& childCell = m_cells.at(childCellId);
			if (childCell.getPassable() == true)
			{
				if (childCellId == t_destCellId)
				{
					goalReached = true;
					m_cells.at(t_destCellId).setPrevious(cellQueue.front().id());
				}
				else if (childCell.isMarked() == false)
				{
					//else we have not find the destination
					m_cells.at(childCellId).setPrevious(cellQueue.front().id());
					childCell.setMarked(true);
					cellQueue.push(childCell);
				}
			} 
			else
			{
				std::cout << childCellId << " is blocked " << std::endl;
			}// end if cell is passable	
		}
		cellQueue.pop(); // dequeue
	}
	
	std::vector<int> path;
	int cellIndex = t_destCellId;
	while (m_cells.at(cellIndex).previous() != -1)
	{
		path.push_back(cellIndex);
		cellIndex = m_cells.at(cellIndex).previous();
	}
	path.push_back(cellIndex);

	return path;

}

std::vector<Cell> Grid::getCells()
{
	return m_cells;
}

