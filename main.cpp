#include<SFML/Graphics.hpp>

#include"collect_food.h"

int main()
{
    int current_level = 0;

    collect_food f{};

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "The Christmas Challenge");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (current_level == 0)
                {
                    f.handleEvent(event);
                }
            }
        }

        f.update();

        window.clear();
        f.print(window);
        window.display();
    }

    return 0;
}