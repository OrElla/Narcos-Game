#include "HighScore.h"
#include "Exit.h"
#include "SoundIcon.h"
#include "Choosing.h"

// manage high score screen
HighScore::HighScore()
{
	m_tableScore[NUM_OF_HS] = { 0 };

	m_sprites.resize(3); //change

	m_sprite[0].setTexture(*(FileManager::getInstance().getIconTexture(WEED)));
	m_sprite[0].setOrigin(m_sprite[0].getGlobalBounds().width / 2, 0);
	m_sprite[0].setPosition((WINDOW_LENGTH / 2.f), 50);
	m_sprite[1].setTexture(*(FileManager::getInstance().getScreen(HIGH_SCORE)));

	m_sprites[HighSC_ID::NEW_GAME_hs].setTexture(*(FileManager::getInstance().getButtonTexture(NEW_GAME_b)));;
	m_sprites[HighSC_ID::NEW_GAME_hs].setOrigin(m_sprites[HighSC_ID::NEW_GAME_hs].getGlobalBounds().width / 2,
		m_sprites[HighSC_ID::NEW_GAME_hs].getGlobalBounds().height / 2);
	m_sprites[HighSC_ID::NEW_GAME_hs].setPosition((WINDOW_LENGTH / 2.f) ,
		(WINDOW_HEIGHT / 2.f) - 260);


	m_sprites[HighSC_ID::SOUND_hs].setTexture(*(FileManager::getInstance().getButtonTexture(SOUND_b)));;
	m_sprites[HighSC_ID::SOUND_hs].setOrigin(m_sprites[HighSC_ID::SOUND_hs].getGlobalBounds().width / 2,
		m_sprites[HighSC_ID::SOUND_hs].getGlobalBounds().height / 2);
	m_sprites[HighSC_ID::SOUND_hs].setPosition((WINDOW_LENGTH / 2.f) + 330,
		(WINDOW_HEIGHT / 2.f) + 300);

	m_sprites[HighSC_ID::EXIT_hs].setTexture(*(FileManager::getInstance().getButtonTexture(EXIT_b)));;
	m_sprites[HighSC_ID::EXIT_hs].setOrigin(m_sprites[HighSC_ID::EXIT_hs].getGlobalBounds().width / 2,
		m_sprites[HighSC_ID::EXIT_hs].getGlobalBounds().height / 2);
	m_sprites[HighSC_ID::EXIT_hs].setPosition((WINDOW_LENGTH / 2.f),
		(WINDOW_HEIGHT / 2.f) + 300);


	if (!font.loadFromFile("fonts/Latinia.ttf"))
	{
		std::cout << "error font";
	}

	add("New Game", std::make_unique<Choosing>());
	add("Sound Icon", std::make_unique<SoundIcon>());
	add("Exit", std::make_unique<Exit>());

	getUpdatedScore(m_tableScore);
}


void HighScore::add(std::string name, std::unique_ptr<Command>c)
{
	m_options.emplace_back(option(name, std::move(c)));
}


void HighScore::execute(sf::RenderWindow &window)
{
	sf::Event event;
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				m_options[EXIT_hs].second->execute(window);

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

		auto score = FileManager::getInstance().loadHighScore();
		for (auto &sprite1 : m_sprite)
			window.draw(sprite1);
		for (auto &sprite : m_sprites)
			window.draw(sprite);
		for (int i = 0; i < TOP_5; i++)
		{
			listScore[i].setFont(font);
			listScore[i].setString(score[i].name);
			listScore[i].setStyle(sf::Text::Bold);

			listScore[i].setCharacterSize(30);
			listScore[i].setFillColor(sf::Color::Black);
			listScore[i].setPosition({ 220.f, 321.f + 50 * i });
			window.draw(listScore[i]);

			listScore[i].setString(std::to_string(score[i].score));
			listScore[i].setCharacterSize(30);
			listScore[i].setFillColor(sf::Color::Yellow);
			listScore[i].setPosition({ 503.f, 321.f + 50 * i });
			m_tableScore[i] = score[i].score;
			window.draw(listScore[i]);
		}
		window.display();
		window.clear();
	}
}

void HighScore::getUpdatedScore(int m_tableScore[])
{
	auto score = FileManager::getInstance().loadHighScore();
	for (int i = 0; i < TOP_5; i++)
		m_tableScore[i] = score[i].score;
}


