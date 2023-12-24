#pragma once

#include<SFML/Graphics.hpp>

#include<chrono>

struct raindeer_road
{
	raindeer_road();

	auto update() -> void;
	auto handleEvent(sf::Event& e) -> void;
	auto isDone() -> bool;
	auto print(sf::RenderWindow& w) -> void;

	auto moveLeft() -> void;
	auto moveRight() -> void;
	auto moveForward() -> void;
	auto moveBackwards() -> void;
	auto random_number(int x, int y) -> sf::Vector2f;

	sf::Texture reindeer_texture;
	sf::Sprite reindeer_sprite;

	sf::Texture santa_texture;
	sf::Sprite santa_sprite;

	sf::Texture background_texture;
	sf::Sprite background_sprite;

	std::vector<sf::Sprite> reindeers{};

	bool isDead = false;

	std::chrono::system_clock::time_point last_time = std::chrono::system_clock::now();
};