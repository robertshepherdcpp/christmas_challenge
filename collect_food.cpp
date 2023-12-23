#pragma once

#include<SFML/Graphics.hpp>

#include<random>
#include<ranges>
#include<iostream>

#include "collect_food.h"

collect_food::collect_food()
{
	back_ground_t.loadFromFile("collect_food_background.png");
	back_ground_s.setTexture(back_ground_t);

	santa_t.loadFromFile("santa.png");
	santa_s.setTexture(santa_t);

	carrot_t.loadFromFile("carrot.png");
	carrot_s.setTexture(carrot_t);

	mince_pie_t.loadFromFile("mincepie.png");
	mince_pie_s.setTexture(mince_pie_t);

	santa_s.setPosition(sf::Vector2f(0, 0));

	for (const auto i : std::ranges::views::iota(0) | std::ranges::views::take(10))
	{
		auto copy_sprite = carrot_s;
		copy_sprite.setPosition(random_number_pair(950, 950));
		carrots.push_back(copy_sprite);
	}

	for (const auto i : std::ranges::views::iota(0) | std::ranges::views::take(10))
	{
		auto copy_sprite = mince_pie_s;
		copy_sprite.setPosition(random_number_pair(950, 950));
		mince_pies.push_back(copy_sprite);
	}

	current_index_carrots = carrots.size() - 1;
	current_index_mince_pies = mince_pies.size() - 1;
}

auto collect_food::moveForward() -> void
{
	if (santa_s.getPosition().y <= 1000 || true)
	{
		santa_s.setPosition(sf::Vector2f(santa_s.getPosition().x, (santa_s.getPosition().y - santa_s.getGlobalBounds().height)));
	}
}

auto collect_food::moveBackwards() -> void
{
	if (santa_s.getPosition().y >= 0 || true)
	{
		santa_s.setPosition(sf::Vector2f(santa_s.getPosition().x, (santa_s.getPosition().y + santa_s.getGlobalBounds().height)));
	}
}

auto collect_food::moveLeft() -> void
{
	if (santa_s.getPosition().x >= 0 || true)
	{
		santa_s.setPosition(sf::Vector2f((santa_s.getPosition().x - santa_s.getGlobalBounds().width), santa_s.getPosition().y));
	}
}

auto collect_food::moveRight() -> void
{
	if (santa_s.getPosition().x <= 1000 || true)
	{
		santa_s.setPosition(sf::Vector2f((santa_s.getPosition().x + santa_s.getGlobalBounds().width), santa_s.getPosition().y));
	}
}

auto collect_food::handleEvent(sf::Event& v) -> void
{
	if (v.key.code == sf::Keyboard::A)
	{
		moveLeft();
	}
	if (v.key.code == sf::Keyboard::S)
	{
		moveBackwards();
	}
	if (v.key.code == sf::Keyboard::D)
	{
		moveRight();
	}
	if (v.key.code == sf::Keyboard::W)
	{
		moveForward();
	}
}

auto collect_food::isDone() -> bool
{
	return (num_mince_pies_collected - num_carrots_collected) >= 5;
}

auto collect_food::update() -> void
{
	if (santa_s.getGlobalBounds().intersects(carrots[current_index_carrots].getGlobalBounds()))
	{
		num_carrots_collected += 1;
		if (current_index_mince_pies -= 1)
		{
			current_index_carrots -= 1;
		}
		carrots.pop_back();
		std::cout << "carrot eaten\n";
	}
	if (santa_s.getGlobalBounds().intersects(mince_pies[current_index_mince_pies].getGlobalBounds()))
	{
		num_mince_pies_collected += 1;
		if (current_index_mince_pies >= 1)
		{
			current_index_mince_pies -= 1;
		}
		mince_pies.pop_back();
		std::cout << "mince pie eaten\n";
	}
}

auto collect_food::print(sf::RenderWindow& w) -> void
{
	w.draw(back_ground_s);
	if (current_index_carrots >= 0 || current_index_mince_pies >= 0)
	{
		w.draw(carrots[current_index_carrots]);
		w.draw(mince_pies[current_index_mince_pies]);
	}
	w.draw(santa_s);
}

auto collect_food::random_number_pair(int x, int y) -> sf::Vector2f
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> random_thing(0, x);
	std::uniform_int_distribution<std::mt19937::result_type> random_thing_two(0, y);

	return sf::Vector2f(random_thing(rng), random_thing_two(rng));
}
