#include "GameOverDead.h"
#include "Exit.h"
#include "SoundIcon.h"
#include "Choosing.h"
//-----------------------------------------------------------------------------

GameOverDead::GameOverDead()
{
	m_sprites.resize(3); //change
						 //change files
	m_sprite[0].setTexture(*(FileManager::getInstance().getIconTexture(WEED)));
	m_sprite[0].setOrigin(m_sprite[0].getGlobalBounds().width / 2, 0);
	m_sprite[0].setPosition((WINDOW_LENGTH / 2.f), 50);
	m_sprite[1].setTexture(*(FileManager::getInstance().getScreen(GO_SHOT)));
	m_sprite[2].setTexture(*(FileManager::getInstance().getScreen(GO_DEAD)));


	m_sprites[GO_WON_ID::NEW_GAME_WON].setTexture(*(FileManager::getInstance().getButtonTexture(NEW_GAME_b)));;
	m_sprites[GO_WON_ID::NEW_GAME_WON].setOrigin(m_sprites[GO_WON_ID::NEW_GAME_WON].getGlobalBounds().width / 2,
		m_sprites[GO_WON_ID::NEW_GAME_WON].getGlobalBounds().height / 2);
	m_sprites[GO_WON_ID::NEW_GAME_WON].setPosition((WINDOW_LENGTH / 2.f),
		(WINDOW_HEIGHT / 2.f) + 20);

	m_sprites[GO_WON_ID::SOUND_WON].setTexture(*(FileManager::getInstance().getButtonTexture(SOUND_b)));;
	m_sprites[GO_WON_ID::SOUND_WON].setOrigin(m_sprites[GO_WON_ID::SOUND_WON].getGlobalBounds().width / 2,
		m_sprites[GO_WON_ID::SOUND_WON].getGlobalBounds().height / 2);
	m_sprites[GO_WON_ID::SOUND_WON].setPosition((WINDOW_LENGTH / 2.f) + 330,
		(WINDOW_HEIGHT / 2.f) + 300);

	m_sprites[GO_WON_ID::EXIT_WON].setTexture(*(FileManager::getInstance().getButtonTexture(EXIT_b)));;
	m_sprites[GO_WON_ID::EXIT_WON].setOrigin(m_sprites[GO_WON_ID::EXIT_WON].getGlobalBounds().width / 2,
		m_sprites[GO_WON_ID::EXIT_WON].getGlobalBounds().height / 2);
	m_sprites[GO_WON_ID::EXIT_WON].setPosition((WINDOW_LENGTH / 2.f), (WINDOW_HEIGHT / 2.f) + 150);


	add("CHOOSING", std::make_unique<Choosing>());
	add("SOUND", std::make_unique<SoundIcon>());
	add("Exit", std::make_unique<Exit>());
}
//-----------------------------------------------------------------------------


void GameOverDead::add(std::string name, std::unique_ptr<Command>c)
{
	m_options.emplace_back(option(name, std::move(c)));
}

//--------------------------------------------------------
//MANAGE THE SCREEN OF G.O IF YOU DEAD
void GameOverDead::execute(sf::RenderWindow &window)
{
	sf::Event event;
	window.create(sf::VideoMode(WINDOW_LENGTH, WINDOW_HEIGHT + 50), "NARCOS - go_DEAD");

	sf::Clock clock;
	float time = 3.0f;
	clock.restart();
	while (window.isOpen())
	{

		if (clock.getElapsedTime().asSeconds() < time)
				window.draw(m_sprite[1]);
			
		else {
			window.draw(m_sprite[0]);
			window.draw(m_sprite[2]);
			for (auto &sprite : m_sprites)   //draw
				window.draw(sprite);
		}

		window.display();
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				m_options[EXIT_WON].second->execute(window);

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


