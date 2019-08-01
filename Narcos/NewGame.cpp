#include "NewGame.h"
#include "Controller.h"
//-----------------------------------------------------------------------------
NewGame::NewGame()
{

}

//-----------------------------------------------------------------------------
NewGame::~NewGame()
{
}


//--------------------------------------------------------
//MANAGE THE SCREEN OF NEW GAME
void NewGame::execute(sf::RenderWindow& window)
{
	window.clear();
	Controller gameController;
	gameController.run(window);
}
