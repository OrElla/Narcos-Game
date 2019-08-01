#include "SoundIcon.h"

SoundIcon::SoundIcon()
{

}


void SoundIcon::add(std::string name, std::unique_ptr<Command>c)
{
	m_options.emplace_back(option(name, std::move(c)));
}


void SoundIcon::execute(sf::RenderWindow &window)
{
	sf::Event event;
	while (window.isOpen())
	{
		//for (auto &sprite : m_sprites)   //draw
		//window.draw(sprite);


		window.display();   //display
							//sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				m_options[EXIT_CHOOSE].second->execute(window);


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



