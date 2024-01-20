#include "car.h"
#include <iostream>

sf::Texture car::texture;

car::car(float x, float y) {
	texture.loadFromFile("car2.png");
	sprite.setTexture(texture);
	sprite.setOrigin(get_centre());
	sprite.setPosition(x, y);
	velocity = { 0, 0 };
}

void car::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}

void car::acc() {
	if (speed < consts::max_speed) speed += consts::acc;
	else if (speed < 0) speed += consts::breaks;
}

void car::dec() {
	if (speed > -consts::max_speed) speed -= consts::acc;
	else if (speed > 0) speed -= consts::breaks;
}

void car::speed_check() {
	if (speed - consts::dec > 0) speed -= consts::dec;
	else if (speed + consts::dec < 0) speed += consts::dec;
	else speed = 0;
}

void car::left() {
	if (abs(speed) < 1) return;
	else if (abs(speed) < 6) angle -= consts::turn_speed - 0.04f;
	else angle -= abs((consts::turn_speed * abs(speed) / consts::max_speed) - consts::turn_speed);
}

// turn_speed 0.08 , speed -40->40, max_speed 40 

void car::right() {
	if (abs(speed) < 1) return;
	else if (abs(speed) < 6) angle += consts::turn_speed - 0.04f;
	else angle += abs((consts::turn_speed * abs(speed) / consts::max_speed) - consts::turn_speed);
}

void car::update() {
	velocity = { sin(angle) * speed, -cos(angle) * speed };
	sprite.move(velocity);
	sprite.setRotation(angle * 180.0f / 3.141592f);
}

sf::Vector2f car::get_pos() {
	return sprite.getPosition();
}