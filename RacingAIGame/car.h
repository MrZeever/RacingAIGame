#pragma once
#ifndef CAR_H
#define CAR_H

#include "consts.h"
#include "entity.h"

class car : public entity {
	static sf::Texture texture;
	sf::Vector2f velocity;
	float speed = 0, angle = 0, distance=0, time=0;
	void check_distance();
public:
	car(float x, float y);

	void update();

	void draw(sf::RenderWindow& window) override;

	void acc();

	void dec();

	void speed_check();

	void left();

	void right();

	sf::Vector2f get_pos();
};

#endif // !CAR_H