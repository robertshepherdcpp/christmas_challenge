#pragma once

#include<SFML/Graphics.hpp>

#include<vector>

struct collect_food
{
	collect_food();

	auto moveForward() -> void;
	auto moveBackwards() -> void;
	auto moveLeft() -> void;
	auto moveRight() -> void;

	auto handleEvent(sf::Event& v) -> void;

	auto isDone() -> bool;
	auto update() -> void;
	auto print(sf::RenderWindow& w) -> void;
	
	auto random_number_pair(int x, int y) -> sf::Vector2f;

	sf::Texture back_ground_t;
	sf::Sprite back_ground_s;

	sf::Texture santa_t;
	sf::Sprite santa_s;

	sf::Texture carrot_t;
	sf::Sprite carrot_s;

	sf::Texture mince_pie_t;
	sf::Sprite mince_pie_s;

	std::vector<sf::Sprite> carrots{};
	std::vector<sf::Sprite> mince_pies{};

	int current_index_carrots = 0;
	int current_index_mince_pies = 0;

	int num_carrots_collected = 0;
	int num_mince_pies_collected = 0;
};