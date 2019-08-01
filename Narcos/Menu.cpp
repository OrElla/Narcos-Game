#include "Menu.h"
#include "Choosing.h"
#include "Introduction.h"
#include "HighScore.h"
#include "SoundIcon.h"
#include "Exit.h"

//-----------------------------------------------------------------------------
Menu::Menu()
{
	m_sound.openFromFile("sounds/open_game.ogg");
	m_window.create(sf::VideoMode(WINDOW_LENGTH, WINDOW_HEIGHT + 50), "NARCOS - MENU");
	m_sprites.resize(5); //change

	//TODO ~~~!!! 

	m_sprite[0].setTexture(*(FileManager::getInstance().getIconTexture(WEED)));
	m_sprite[0].setOrigin(m_sprite[0].getGlobalBounds().width / 2, 0);
	m_sprite[0].setPosition((WINDOW_LENGTH / 2.f), 50);
	m_sprite[1].setTexture(*(FileManager::getInstance().getScreen(Menu_s)));

	m_sprites[Menu_ID::CHOOSING_BUTTON].setTexture(*(FileManager::getInstance().getButtonTexture(NEW_GAME_b)));;
	m_sprites[Menu_ID::CHOOSING_BUTTON].setOrigin(m_sprites[Menu_ID::CHOOSING_BUTTON].getGlobalBounds().width / 2,
		m_sprites[Menu_ID::CHOOSING_BUTTON].getGlobalBounds().height / 2);
	m_sprites[Menu_ID::CHOOSING_BUTTON].setPosition((WINDOW_LENGTH / 2.f),
		(WINDOW_HEIGHT / 2.f) - 20);

	m_sprites[Menu_ID::INTRO__BUTTON].setTexture(*(FileManager::getInstance().getButtonTexture(INTRO_b)));;
	m_sprites[Menu_ID::INTRO__BUTTON].setOrigin(m_sprites[Menu_ID::INTRO__BUTTON].getGlobalBounds().width / 2,
		m_sprites[Menu_ID::INTRO__BUTTON].getGlobalBounds().height / 2);
	m_sprites[Menu_ID::INTRO__BUTTON].setPosition((WINDOW_LENGTH / 2.f), (WINDOW_HEIGHT / 2.f) + 30);

	m_sprites[Menu_ID::HS_BUTTON].setTexture(*(FileManager::getInstance().getButtonTexture(HS_b)));;
	m_sprites[Menu_ID::HS_BUTTON].setOrigin(m_sprites[Menu_ID::HS_BUTTON].getGlobalBounds().width / 2,
		m_sprites[Menu_ID::HS_BUTTON].getGlobalBounds().height / 2);
	m_sprites[Menu_ID::HS_BUTTON].setPosition((WINDOW_LENGTH / 2.f), (WINDOW_HEIGHT / 2.f) + 90);

	m_sprites[Menu_ID::EXIT_BUTTON].setTexture(*(FileManager::getInstance().getButtonTexture(EXIT_b)));;
	m_sprites[Menu_ID::EXIT_BUTTON].setOrigin(m_sprites[Menu_ID::EXIT_BUTTON].getGlobalBounds().width / 2,
		m_sprites[Menu_ID::EXIT_BUTTON].getGlobalBounds().height / 2);
	m_sprites[Menu_ID::EXIT_BUTTON].setPosition((WINDOW_LENGTH / 2.f), (WINDOW_HEIGHT / 2.f) + 150);

	m_sprites[Menu_ID::SOUND_BUTTON].setTexture(*(FileManager::getInstance().getButtonTexture(SOUND_b)));;
	m_sprites[Menu_ID::SOUND_BUTTON].setOrigin(m_sprites[Menu_ID::SOUND_BUTTON].getGlobalBounds().width / 2,
		m_sprites[Menu_ID::SOUND_BUTTON].getGlobalBounds().height / 2);
	m_sprites[Menu_ID::SOUND_BUTTON].setPosition((WINDOW_LENGTH / 2.f) + 330,
		(WINDOW_HEIGHT / 2.f) + 300);

	add("New Game", std::make_unique<Choosing>());
	add("Introduction", std::make_unique<Introduction>());
	add("HIGH SCORE", std::make_unique<HighScore>());
	add("Sound ICON", std::make_unique<SoundIcon>());
	add("Exit", std::make_unique<Exit>());
}


//--------------------------------------------------------
//MANAGE THE SCREEN OF THE MENU 
void Menu::activate()
{
	execute(m_window);
}

void Menu::execute(sf::RenderWindow &)
{
	sf::Clock c;
	c.restart();
	m_sound.setVolume(70);
	m_sound.play();
	sf::Event event;
	while (m_window.isOpen())
	{
		if (c.getElapsedTime().asSeconds() > 10)
			m_sound.stop();
		for (auto &sprite1 : m_sprite)   //draw
			m_window.draw(sprite1);
		for (auto &sprite : m_sprites)   //draw
			m_window.draw(sprite);
		m_window.display();   //display

		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				m_options[EXIT_BUTTON].second->execute(m_window);

			auto  increase = sf::Mouse::getPosition(m_window);
			for (int i = 0; i < m_sprites.size(); i++)
			{
				if (m_sprites[i].getGlobalBounds().contains(sf::Vector2f(increase))){
					m_sprites[i].setScale(0.8,0.8);
				}
				else{
					m_sprites[i].setScale(1.f, 1.f);
				}
			}

			if (event.type == sf::Event::MouseButtonPressed) {
				if (event.mouseButton.button == sf::Mouse::Left)
					for (int i = 0; i < m_sprites.size(); i++)
						if (m_sprites[i].getGlobalBounds().contains((float)event.mouseButton.x,
							(float)event.mouseButton.y))
							m_options[i].second->execute(m_window);
			}
		}
	}
	m_window.clear();
}

//-----------------------------------------------------------------------------
void Menu::add(std::string name, std::unique_ptr<Command> c)
{
	m_options.emplace_back(option(name, std::move(c)));
}

