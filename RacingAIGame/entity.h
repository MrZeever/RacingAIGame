#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class entity {
protected:
	sf::Sprite sprite;
	bool destroyed{ false };
public:
	virtual void draw(sf::RenderWindow& window) = 0;

	sf::FloatRect get_bounding_box() const noexcept;

	sf::Vector2f get_centre() const noexcept;

	sf::Sprite return_sprite();

	float x() const noexcept;
	float y() const noexcept;

	float left() const noexcept;
	float right() const noexcept;
	float top() const noexcept;
	float bottom() const noexcept;

	void destory() noexcept;
	bool is_destroyed() const noexcept;

	virtual ~entity() {}
};
#endif // !ENTITY_H