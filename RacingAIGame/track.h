#pragma once
#ifndef TRACK_H
#define TRACK_H

#include "Consts.h"
#include "entity.h"

class track : public entity {
	static sf::Texture texture;
	float start_x{ 0 }, start_y{ 0 }, finish_x{ 0 }, finish_y{0};
	std::vector<float> start_line{ 0,0,0,0 };  // x1 y1 x2 y2
	std::vector<float> finish_line{ 0,0,0,0 };
	double time=0;
public:
	track(float x, float y, std::string track_name);

	void draw(sf::RenderWindow& window) override;
};

#endif // !TRACK_H