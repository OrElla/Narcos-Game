#include "Level.h"

//--------------------------------------------------------
// CONTRUCTOR LEVEL
Level::Level(vector<shared_ptr<DynamicIcon>> & Dynamics, int levelNumber)
{
	read_level(Dynamics, levelNumber);
}

//--------------------------------------------------------
// DEFINES THE BOARD SIZE
sf::Vector2f Level::getBoardSize()
{
	sf::Vector2f boardSize;
	boardSize.x = m_board.size()* P_SIZE;
	boardSize.y = m_board[0].size() * P_SIZE;
	return boardSize;
}

//--------------------------------------------------------
// DRAWING THE STATIC OBJECTS
void Level::drawStatic(sf::RenderWindow & window)
{
	for (size_t i = 0; i < m_board.size(); i++)
	{
		for (size_t j = 0; j < m_board[i].size(); j++)
		{
		
			if (m_board[i][j] != nullptr)
				m_board[i][j]->draw(window, 
					sf::Vector2f(j*P_SIZE, i*P_SIZE));
		}
	}
}
//--------------------------------------------------------
// READING THE LEVEL AND DEFINES IT ACCORDING THE FILE
void Level::read_level(vector<shared_ptr<DynamicIcon>> & Dynamics, int levelNumber)
{
	ifstream input;
	open_file(input, levelNumber);

	int rows, cols;
	char c;

	input >> rows >> cols;
	setBoardSize(rows, cols);

	for (size_t i = 0; i < rows; i++)
	{
		input.get();
		for (size_t j = 0; j < cols; j++)
		{
			c = input.get();
			if (c == 'C')
				int x =0;
			add_to_board(c, i, j, Dynamics);
		}
	}
}

void Level::clearAll()
{
	for (int i = 0; i < m_board.size(); i++)
		m_board[i].clear();

	m_board.clear();
	m_statics.clear();
}

/*
void Level::setPoliceMan(vector<std::unique_ptr<PoliceMan>>& m_PoliceMan,
	sf::Vector2f pos)
{

	if (!m_PoliceMan.size() % 2 == 0)
		m_PoliceMan.push_back(std::make_unique < PoliceMan >());
	else //change!!!!!!!!
		m_PoliceMan.push_back(std::make_unique <PoliceMan>());

	int size = (int)m_PoliceMan.size() - 1;
	m_PoliceMan[size]->SetPosition(pos);
	m_PoliceMan[size]->setStartingPosition(pos);
}
*/

//--------------------------------------------------------
// DELETE OBJECT
void Level::deleteObj(int index)
{
	for (size_t i = 0; i < m_board.size(); i++)
		for (size_t j = 0; j < m_board[0].size(); j++)
			if (m_board[i][j] != nullptr && !m_board[i][j]->getExist())
			{
				m_board[i][j] = nullptr;
				m_statics.erase(m_statics.begin() + index);
			}
}

//--------------------------------------------------------
// GET STATIC ICON
StaticIcon * Level::getIcon(sf::Vector2f pos)
{	
		int i = pos.y / P_SIZE;
		int j = pos.x / P_SIZE;
		return m_board[i][j].get();	
}

//--------------------------------------------------------
// SET THE BOARD 
vector<vector<std::shared_ptr<StaticIcon>>>& Level::setBoard() 
{
	return m_board;
}

//--------------------------------------------------------
// GET STATIC OBJECTS
vector<shared_ptr<StaticIcon>>& Level::getStatics()
{
	return m_statics;
}

//--------------------------------------------------------
// OPEN RHE FILE ACCORDING THE PATH
void Level::open_file(ifstream & input, int levelNumber)
{
	std::string file = "levels/" + std::to_string(levelNumber) + ".txt";
	input.open(file);


	if (!input.is_open())
	{
		throw InvalidPath();

		std::cerr << "could not open file\n";
		exit(EXIT_FAILURE);
	}
}
//--------------------------------------------------------
// SET THE BOARD SIZE
void Level::setBoardSize(int rows, int cols)
{
	m_board.resize(rows);
	for (size_t i = 0; i < rows; i++)
		m_board[i].resize(cols);
}

//--------------------------------------------------------
//  ADD OBJECTS TO THE BOARD

void Level::add_to_board(char c, size_t i,
	size_t j, vector<shared_ptr<DynamicIcon>> & m_Dynamics)
{
	std::shared_ptr<StaticIcon> staticObj = FactoryStatic::Create(c);
	if (staticObj){
		m_board[i][j] = staticObj;
		m_statics.emplace_back(staticObj);
	}

	else{
		auto dynamicObj = FactoryDynamic::Create(c);
		if (dynamicObj)
		{
			m_Dynamics.emplace_back(move(dynamicObj));
			m_Dynamics.back()->SetPosition(sf::Vector2f(j*P_SIZE, i*P_SIZE));
		}
	}
}

//--------------------------------------------------------
// DELETES OBJECTS FROM THE BOARD 
void Level::deleteObj(sf::Vector2f v)
{
	int i = v.y / P_SIZE;
	int j = v.x / P_SIZE;
	m_board[i][j] = nullptr;
}
