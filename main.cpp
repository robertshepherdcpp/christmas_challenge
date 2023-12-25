#include<SFML/Graphics.hpp>

#include<iostream>

#include"collect_food.h"
#include"raindeer_road.h"

// Merry Christmas!

int main()
{
    int current_level = 0;
    bool has_printed_first_level_instructions = false;
    bool has_printed_second_level_instructions = false;

    collect_food f{};
    raindeer_road r{};

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "The Christmas Challenge");
    while (window.isOpen())
    {
        if (current_level == 0 && !has_printed_first_level_instructions)
        {
            std::cout << "Try to collect all 5 mince pies, but make sure not to eat the carrots as they are for the reindeer!\n";
            has_printed_first_level_instructions = true;
        }
        if (current_level == 1 && !has_printed_second_level_instructions)
        {
            std::cout << "Try to cross the road full of fast moving reindeer!\n";
            has_printed_second_level_instructions = true;
        }
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
                if (current_level == 1)
                {
                    r.handleEvent(event);
                }
            }
        }

        window.clear();
        if (current_level == 0)
        {
            f.update();
            if (f.isDone())
            {
                std::cout << "First level complete!\n";
                std::cout << "You now have enough energy to go on your trip!\n";
                current_level += 1;
            }
            f.print(window);
        }
        else if (current_level == 1)
        {
            r.update();
            if (r.isDone())
            {
                std::cout << "Second level complete!\n";
                std::cout << "Time to go and pack some presents!\n";
                current_level += 1;
            }
            r.print(window);
        }
        window.display();
    }

    return 0;
}