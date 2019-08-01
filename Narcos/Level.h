#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include "SFML\Graphics.hpp"
#include <memory>
#include <vector>
#include "StaticIcon.h"
#include "Pablo.h"
#include "PoliceMan.h"
#include "FactoryStatic.h"
//#include "Bullet.h"

using std::ifstream;
using std::vector;
class Controller;

//const int NUM_OF_LEVELS = 5;

class Level
{
public:
	Level(vector<std::shared_ptr<DynamicIcon>>& m_Dynamics,int levelNumber);
	sf::Vector2f getBoardSize();
	void drawStatic(sf::RenderWindow & window);
	void read_level(vector<std::shared_ptr<DynamicIcon>>& m_Dynamics, int levelNumber);
	void clearAll();
	//void setPablo(Pablo & pab, sf::Vector2f pos);
	//void setPoliceMan(vector<std::unique_ptr<PoliceMan>>& m_PoliceMan,
		   //sf::Vector2f pos);

	void deleteObj(sf::Vector2f v);
	void deleteObj(int index);
	StaticIcon * getIcon(sf::Vector2f pos);
	vector <vector<std::shared_ptr<StaticIcon>>> & setBoard();
	vector<std::shared_ptr<StaticIcon>> & getStatics();

	// create bullet

private:
	void open_file(ifstream& input, int levelNumber);
	vector <vector<std::shared_ptr<StaticIcon>>> m_board;
	void setBoardSize(int rows, int cols); // ?
	void add_to_board(char c, size_t i, size_t j, 
		vector<std::shared_ptr<DynamicIcon>>& m_Dynamics);
	vector<std::shared_ptr<StaticIcon>> m_statics;
};

