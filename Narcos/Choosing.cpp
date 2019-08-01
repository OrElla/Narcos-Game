#include "Choosing.h"
#include "NewGame.h"
#include "Exit.h"

//--------------------------------------------------------
//CONSTRUCTOR

Choosing::Choosing()
{
	m_sprites.resize(3); //change

	//change files
	m_sprite[0].setTexture(*(FileManager::getInstance().getIconTexture(WEED)));
	m_sprite[0].setOrigin(m_sprite[0].getGlobalBounds().width / 2, 0);
	m_sprite[0].setPosition((WINDOW_LENGTH / 2.f), 50);
	m_sprite[1].setTexture(*(FileManager::getInstance().getScreen(CHOOSE_CHARACTER)));


	m_sprites[Choose_ID::PLAY_PABLO].setTexture(*(FileManager::getInstance().getPlayerTexture(P1)));
	m_sprites[Choose_ID::PLAY_PABLO].setOrigin(m_sprites[Choose_ID::PLAY_PABLO].getGlobalBounds().width / 2,
		m_sprites[Choose_ID::PLAY_PABLO].getGlobalBounds().height / 2);
	m_sprites[Choose_ID::PLAY_PABLO].setPosition((WINDOW_LENGTH / 2)-200, (WINDOW_HEIGHT / 2.f));


	m_sprites[Choose_ID::PLAY_GACHA].setTexture(*(FileManager::getInstance().getIconTexture(GACHA)));;
	m_sprites[Choose_ID::PLAY_GACHA].setOrigin(m_sprites[Choose_ID::PLAY_GACHA].getGlobalBounds().width / 2,
		m_sprites[Choose_ID::PLAY_GACHA].getGlobalBounds().height / 2);
	m_sprites[Choose_ID::PLAY_GACHA].setPosition((WINDOW_LENGTH / 2.f+200), (WINDOW_HEIGHT / 2.f));

	m_sprites[Choose_ID::EXIT_CHOOSE].setTexture(*(FileManager::getInstance().getButtonTexture(EXIT_b)));;
	m_sprites[Choose_ID::EXIT_CHOOSE].setOrigin(m_sprites[Choose_ID::EXIT_CHOOSE].getGlobalBounds().width / 2,
		m_sprites[Choose_ID::EXIT_CHOOSE].getGlobalBounds().height / 2);
	m_sprites[Choose_ID::EXIT_CHOOSE].setPosition((WINDOW_LENGTH / 2.f), (WINDOW_HEIGHT / 2.f) + 250);



	add("New pablo", std::make_unique<NewGame>());
	add("New Gacha", std::make_unique<NewGame>());
	add("Exit", std::make_unique<Exit>());

}

// ADDS BUTTONS TO THIS SCREEN
void Choosing::add(std::string name, std::unique_ptr<Command>c)
{
	m_options.emplace_back(option(name, std::move(c)));
}

//--------------------------------------------------------
//MANAGE THE SCREEN OF SELECT PLAYER
void Choosing::execute(sf::RenderWindow &window)
{
	sf::Event event;
	while (window.isOpen())
	{
		for (auto &sprite1 : m_sprite)
			window.draw(sprite1);
		//for (auto &sprite : m_sprites)   
		//	window.draw(sprite);
		window.display();   
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				m_options[EXIT_CHOOSE].second->execute(window);


			auto  increase = sf::Mouse::getPosition(window);
			for (int i = 0; i < m_sprites.size(); i++)
			{
				if (m_sprites[i].getGlobalBounds().contains(sf::Vector2f(increase))) {
					m_sprites[i].setScale(0.8, 0.8);
				}
				else {
					m_sprites[i].setScale(1.f, 1.f);
				}
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					for (int i = 0; i < m_sprites.size(); i++)
					{
						if (m_sprites[i].getGlobalBounds().contains((float)event.mouseButton.x,
							(float)event.mouseButton.y))
							m_options[i].second->execute(window);
					}
				}
			}
		}
		window.clear();
	}
}