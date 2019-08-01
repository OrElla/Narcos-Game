#include "EnterScore.h"
#include "SoundIcon.h"

//manage the screen of enetring new score
EnterScore::EnterScore()
{
	m_screenScore = 0;

	m_sprites.resize(1); 
						 
	m_sprite[0].setTexture(*(FileManager::getInstance().getIconTexture(WEED)));
	m_sprite[0].setOrigin(m_sprite[0].getGlobalBounds().width / 2, 0);
	m_sprite[0].setPosition((WINDOW_LENGTH / 2.f), 50);
	m_sprite[1].setTexture(*(FileManager::getInstance().getScreen(ENTER_SCORE)));


	m_sprites[Enter_ID::OK_enter].setTexture(*(FileManager::getInstance().getButtonTexture(OK_b)));;
	m_sprites[Enter_ID::OK_enter].setOrigin(m_sprites[Enter_ID::OK_enter].getGlobalBounds().width / 2,
		m_sprites[Enter_ID::OK_enter].getGlobalBounds().height / 2);
	m_sprites[Enter_ID::OK_enter].setPosition((WINDOW_LENGTH / 2.f)+90,
		(WINDOW_HEIGHT / 2.f) - 40);
	
	add("High Score", std::make_unique<HighScore>());
	add("SOUND", std::make_unique<SoundIcon>());
}


void EnterScore::add(std::string name, std::unique_ptr<Command>c)
{
	m_options.emplace_back(option(name, std::move(c)));
}


void EnterScore::execute(sf::RenderWindow &window)
{
	sf::Event event;
	sf::Vector2u size;
	size.x = WINDOW_LENGTH;
	size.y = WINDOW_HEIGHT + 50;
	m_sprite[1].setScale(1.0f, ((float)window.getSize().y / size.y));

	window.setSize(sf::Vector2u(size));

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
				m_options[EXIT_WON].second->execute(window);
			if (event.type == sf::Event::MouseMoved)
				std::cout << "X: " << event.mouseMove.x << " y: " <<
				event.mouseMove.y << std::endl;

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
					Enter_ID button =
						getEhsButton(sf::Vector2i(event.mouseButton.x,
							event.mouseButton.y));
					switch (button){
					case INPUT_enter:{
						listHs(window);
						break;
					}
					case OK_enter:{
						h.execute(window);
						break;
					}
					default:
						break;
					}
					for (int i = 0; i < m_sprites.size(); i++){
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

Enter_ID EnterScore::getEhsButton(sf::Vector2i buttonPos)
{
	if (buttonPos.x > 246 && buttonPos.x < 437
		&& buttonPos.y > 241 && buttonPos.y < 277)
		return INPUT_enter;

	else if (buttonPos.x > 496 && buttonPos.x < 541
		&& buttonPos.y > 319 && buttonPos.y < 358)
		return OK_enter;
}


void EnterScore::listHs(sf::RenderWindow &window)
{
	if (!font.loadFromFile("fonts/Latinia.ttf"))
	{
		std::cout << "error font";
	}
	sf::String sentence;
	sf::Text text(sentence, font, 25);
	//text.setFillColor(sf::Color(44, 127, 255));
	text.setPosition(263, 240);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::Black);


	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
				break;
			case sf::Event::TextEntered:
			{
				if (sentence.getSize() <= 10)
				{
					if (event.text.unicode >= 32 && event.text.unicode <= 126)
						sentence += (char)event.text.unicode;
					else if (event.text.unicode == 8 && sentence.getSize() > 0)
						sentence.erase(sentence.getSize() - 1, sentence.getSize());

					text.setString(sentence);
				}
				break;
			}

			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					Enter_ID button = getEhsButton(sf::Vector2i(event.mouseButton.x,
						event.mouseButton.y));
					switch (button)
					{
					case OK_enter:
					{
						FileManager::getInstance().updateScore(sentence, m_screenScore);
						h.execute(window);
						break;
					}
					default:
						break;
					}
					for (int i = 0; i < m_sprites.size(); i++)
					{
						if (m_sprites[i].getGlobalBounds().contains((float)event.mouseButton.x,
							(float)event.mouseButton.y))
							m_options[i].second->execute(window);
					}
				}
				break;
			}
		}
		window.draw(m_sprite[1]);
		for (auto &sprite : m_sprites)   //draw
			window.draw(sprite);
		window.draw(text);
		window.display();
		window.clear();
	}
}