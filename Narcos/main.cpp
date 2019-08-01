
#ifdef _DEBUG
#pragma comment ( lib , "sfml-main-d.lib" )
#elif defined (NDEBUG)
#pragma comment ( lib , "sfml-main.lib" )
#else
#error "Unrecognized configuration!"
#endif

#include <SFML/Graphics.hpp>
#include "Execute.h"
#include "Exceptions.h"
#include "Menu.h"


int main() {

	// running opening video

	
	sf::Thread video([&]()
	{
		RunProcess("E_includes\\nnn.exe");
	}
	);
	video.launch();
	Menu menu;
	video.wait();
	menu.activate();
	

	//run the proggram

	//Menu menu;
	//menu.activate();

	getchar();
}