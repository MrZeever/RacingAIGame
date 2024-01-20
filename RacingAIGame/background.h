#pragma once
#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "Consts.h"
#include "entity.h"

class background : public entity {
	static sf::Texture texture;
public:
	background(float x, float y);

	void draw(sf::RenderWindow& window) override;
};

#endif // !BACKGROUND_H