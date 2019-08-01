#include "Introduction.h"
#include "Exit.h"
#include "Choosing.h"
#include "SoundIcon.h"


// manage Introduction screen

Introduction::Introduction()
{
	m_sprites.resize(3); //change

	//change files
	m_sprite[0].setTexture(*(FileManager::getInstance().getIconTexture(WEED)));
	m_sprite[0].setOrigin(m_sprite[0].getGlobalBounds().width / 2, 0);
	m_sprite[0].setPosition((WINDOW_LENGTH / 2.f), 50);
	m_sprite[1].setTexture(*(FileManager::getInstance().getScreen(INTRO)));

	//change to "play"
	m_sprites[Intro_ID::CHOOSING_Intro].setTexture(*(FileManager::getInstance().getButtonTexture(PLAY_b)));;
	m_sprites[Intro_ID::CHOOSING_Intro].setOrigin(m_sprites[Intro_ID::CHOOSING_Intro].getGlobalBounds().width / 2,
		m_sprites[Intro_ID::CHOOSING_Intro].getGlobalBounds().height / 2);
	m_sprites[Intro_ID::CHOOSING_Intro].setPosition((WINDOW_LENGTH / 2.f)+200, (WINDOW_HEIGHT / 4.f)-70);

	m_sprites[Intro_ID::SOUND_Intro].setTexture(*(FileManager::getInstance().getButtonTexture(SOUND_b)));;
	m_sprites[Intro_ID::SOUND_Intro].setOrigin(m_sprites[Intro_ID::SOUND_Intro].getGlobalBounds().width / 2,
		m_sprites[Intro_ID::SOUND_Intro].getGlobalBounds().height / 2);
	m_sprites[Intro_ID::SOUND_Intro].setPosition((WINDOW_LENGTH / 2.f) + 330, (WINDOW_HEIGHT / 2.f) + 300);

	//m_exitButton.setTexture(*(FileManager::getInstance().getButtonTexture(EXIT_b)));;
	//m_exitButton.setOrigin(m_exitButton.getGlobalBounds().width / 2, m_exitButton.getGlobalBounds().height / 2);
	m_sprites[Intro_ID::EXIT_Intro].setPosition((WINDOW_LENGTH / 2.f), (WINDOW_HEIGHT / 2.f) + 200);


	//m_sprites[Intro_ID::MENU_Intro] = m_menu;
	//add("Menu", std::make_unique<Menu>());
	add("New Game", std::make_unique<Choosing>());
	add("Sound ICON", std::make_unique<SoundIcon>());
	add("Exit", std::make_unique<Exit>());

}

void Introduction::add(std::string name, std::unique_ptr<Command>c)
{
	m_options.emplace_back(option(name, std::move(c)));
}

void Introduction::activate()
{
	std::cout << "activate";
}


void Introduction::execute(sf::RenderWindow &window)
{
	sf::Event event;
	while (window.isOpen())
	{
		for (auto &sprite1 : m_sprite)   
			window.draw(sprite1);
		for (auto &sprite : m_sprites) 
			window.draw(sprite);


		window.display();  

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				m_options[EXIT_Intro].second->execute(window);   

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
