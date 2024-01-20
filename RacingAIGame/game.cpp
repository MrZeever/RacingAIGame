#include "game.h"
#include <iostream>

game::game() {
	window.setFramerateLimit(60);
	view.setCenter(0.0f, 0.0f);
	view.setSize(sf::Vector2f(consts::window_width, consts::window_height));
	tracks.emplace_back(0.0f, 0.0f, "map1.png");
}

void game::reset() {
	window.clear(sf::Color::Black);
	menu.draw(window);
	// Go to menu?
}

void game::start() {
	bool up{ 0 }, down{ 0 }, left{ 0 }, right{ 0 };
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {
				window.close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				window.close();
			}

			// menu
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
				state = game_state::menu;
			}

			// singleplayer
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) {
				state = game_state::singleplayer;
			}

			if (game_state::singleplayer == state) {

				// car movement
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
					// acc
					up = 1;
				}
				else up = 0;

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
					// dec
					down = 1;
				}
				else down = 0;

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
					left = 1;
					// turn left
				}
				else left = 0;

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
					right = 1;
					// turn right
				}
				else right = 0;

			}
		}

		window.clear(sf::Color::White);

		if (game_state::menu == state) {
			menu.draw(window);
		}
		else if (game_state::singleplayer == state) {

			if (up) {
				_car.acc();
			}
			else if (down) {
				_car.dec();
			}
			else {
				_car.speed_check();
			}

			if (left) _car.left();
			else if (right) _car.right();
			_car.update();
			tracks.at(0).draw(window);
			view.setCenter(_car.get_pos());
			//tracks.at(0).draw(window);
			is_car_on_track(_car, tracks[0]);
			
			/*if (_car.is_destroyed()) {
				std::cout.clear();
			}*/

			_car.draw(window);
			window.setView(view);
		}


		window.display();
	}
	
}