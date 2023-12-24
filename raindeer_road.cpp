#pragma once

#include<SFML/Graphics.hpp>

#include<chrono>
#include<random>
#include<ranges>
#include<iostream>

#include "raindeer_road.h"

using namespace std::chrono_literals;

raindeer_road::raindeer_road()
{
	reindeer_texture.loadFromFile("reindeer.png");
	reindeer_sprite.setTexture(reindeer_texture);

	santa_texture.loadFromFile("santa.png");
	santa_sprite.setTexture(santa_texture);

	for (const int i : std::ranges::views::iota(0) | std::ranges::views::take(10))
	{
		sf::Sprite copy_sprite = reindeer_sprite;
		copy_sprite.setPosition(random_number(900, 200));
		reindeers.push_back(copy_sprite);
	}
}

auto raindeer_road::update() -> void
{
	if ((std::chrono::system_clock::now() - last_time) >= 10ms)
	{
		for (const int i : std::ranges::views::iota(0) | std::ranges::views::take(10))
		{
			reindeers[i].setPosition(sf::Vector2f(reindeers[i].getPosition().x - 1, reindeers[i].getPosition().y));
			if (reindeers[i].getPosition().x <= 0)
			{
				reindeers[i].setPosition(0, reindeers[i].getPosition().y);
			}
			if (santa_sprite.getGlobalBounds().intersects(reindeers[i].getGlobalBounds()))
			{
				isDead = true;
				std::cout << "Killed by your own reindeer!\n";
			}
		}
	}
}

auto raindeer_road::handleEvent(sf::Event& e) -> void
{
	if (e.key.code == sf::Keyboard::A)
	{
		moveLeft();
	}
	else if (e.key.code == sf::Keyboard::S)
	{
		moveBackwards();
	}
	else if (e.key.code == sf::Keyboard::D)
	{
		moveRight();
	}
	else if (e.key.code == sf::Keyboard::W)
	{
		moveForward();
	}
}

auto raindeer_road::isDone() -> bool
{
	return santa_sprite.getPosition().y >= 300 || isDead;
}

auto raindeer_road::print(sf::RenderWindow& w) -> void
{
	w.draw(background_sprite);
	w.draw(santa_sprite);
	w.draw(reindeer_sprite);
}

auto raindeer_road::moveLeft() -> void
{
	if (santa_sprite.getPosition().x >= 0 || true)
	{
		santa_sprite.setPosition(sf::Vector2f((santa_sprite.getPosition().x - santa_sprite.getGlobalBounds().width), santa_sprite.getPosition().y));
	}
}

auto raindeer_road::moveRight() -> void
{
	if (santa_sprite.getPosition().x <= 1000 || true)
	{
		santa_sprite.setPosition(sf::Vector2f((santa_sprite.getPosition().x + santa_sprite.getGlobalBounds().width), santa_sprite.getPosition().y));
	}
}

auto raindeer_road::moveForward() -> void
{
	if (santa_sprite.getPosition().y <= 1000 || true)
	{
		santa_sprite.setPosition(sf::Vector2f(santa_sprite.getPosition().x, (santa_sprite.getPosition().y - santa_sprite.getGlobalBounds().height)));
	}
}

auto raindeer_road::moveBackwards() -> void
{
	if (santa_sprite.getPosition().y >= 0 || true)
	{
		santa_sprite.setPosition(sf::Vector2f(santa_sprite.getPosition().x, (santa_sprite.getPosition().y + santa_sprite.getGlobalBounds().height)));
	}
}

auto raindeer_road::random_number(int x, int y) -> sf::Vector2f
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> random_thing(0, x);
	std::uniform_int_distribution<std::mt19937::result_type> random_thing_two(0, y);

	return sf::Vector2f(random_thing(rng), random_thing_two(rng));
}