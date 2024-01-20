#pragma once
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "consts.h"
#include "track.h"
#include "background.h"
#include "car.h"
#include "interactions.h"

class game {
	sf::RenderWindow window{ sf::VideoMode(consts::window_width, consts::window_height),"Racing AI" };
	sf::View view;
	background menu{0.0f, 0.0f};
	car _car{ 0.0f, 0.0f };

	std::vector<track> tracks;
	
		
	enum class game_state {
		menu, ai, singleplayer
	};

	game_state state{ game_state::menu };

public:
	game();

	void reset();
	void start();
};

#endif // !GAME_H