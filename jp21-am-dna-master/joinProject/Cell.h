#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

// send aeden
class Cell
{
private:

	int m_id; // the id of the cell
	int m_previousCellId{ -1 }; // the parent id
	bool m_marked; // if mark is false , the algorithm have not reach this cell 
	bool m_isPassable{ true }; // if passable is false , there is a sprite/rectangle on the cell 

	int m_centreX; // the centre of the cell on x axis
	int m_centreY; // the centre of the cell on y axis

	std::vector<int> m_neighbours; //the cells around the current cell 
public:

	/// <summary>
	/// Set the m_isPassable to true or false depending on the bool return 
	/// </summary>
	/// <param name="t_isPassable"></param>
	void setPassable(bool t_isPassable);

	/// <summary>
	/// Set the Id of the cell
	/// </summary>
	/// <param name="Id"></param>
	void setId(int Id);

	/// <summary>
	/// Get the centre point of the cell
	/// </summary>
	/// <param name="t_centre"></param>
	void setCentre(sf::Vector2f t_centre);

	/// <summary>
	/// Set the mark to true if the algorithm have found the cell
	/// </summary>
	/// <param name="t_isMarked"></param>
	void setMarked(bool t_isMarked);

	/// <summary>
	/// Add the neighbours to the cell
	/// </summary>
	/// <param name="t_cellId"></param>
	void addNeighbours(int t_cellId);

	/// <summary>
	/// return a list of neighbours
	/// </summary>
	/// <returns></returns>
	std::vector<int>& neighbours();

	/// <summary>
	/// return the id of the ell
	/// </summary>
	/// <returns></returns>
	int id();

	/// <summary>
	/// check if the cell is marked
	/// </summary>
	/// <returns></returns>
	bool isMarked() const;

	/// <summary>
	/// get the parent cell of the current cell
	/// </summary>
	/// <returns></returns>
	int previous() const;

	/// <summary>
	/// set the parent cell of the current cell
	/// </summary>
	/// <param name="t_previous"></param>
	void setPrevious(int t_previous);

	/// <summary>
	/// return the x and y positon of the cell
	/// </summary>
	/// <returns></returns>
	sf::Vector2f getPosition();

	/// <summary>
	/// check if the cell has obstacle on it 
	/// </summary>
	/// <returns></returns>
	bool getPassable() const;
};